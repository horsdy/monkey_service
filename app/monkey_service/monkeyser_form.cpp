#include "stdafx.h"
#include "monkeyser_form.h"
#include "list_item.h"

MonkeySerForm::MonkeySerForm(const std::wstring& class_name, const std::wstring& theme_directory, const std::wstring& layout_xml)
	: m_class_name(class_name)
	, m_theme_directory(theme_directory)
	, m_layout_xml(layout_xml)
{
}


MonkeySerForm::~MonkeySerForm()
{
}

std::wstring MonkeySerForm::GetSkinFolder()
{
	return m_theme_directory;
}

std::wstring MonkeySerForm::GetSkinFile()
{
	return m_layout_xml;
}

std::wstring MonkeySerForm::GetWindowClassName() const
{
	return m_class_name;
}

void MonkeySerForm::InitWindow()
{
	m_group_list = dynamic_cast<ui::ListBox*>(FindControl(L"group_list"));
	m_service_list = dynamic_cast<ui::ListBox*>(FindControl(L"service_list"));

	/* Regsiter event handler */
	m_pRoot->AttachBubbledEvent(ui::kEventAll, nbase::Bind(&MonkeySerForm::OnNotify, this, std::placeholders::_1));
	return;
}

LRESULT MonkeySerForm::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	PostQuitMessage(0L);
	return __super::OnClose(uMsg, wParam, lParam, bHandled);
}

void MonkeySerForm::ShowCustomWindow(const std::wstring& class_name, const std::wstring& theme_directory, const std::wstring& layout_xml)
{
	MonkeySerForm* window = new MonkeySerForm(class_name, theme_directory, layout_xml);
	window->Create(NULL, class_name.c_str(), WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX, 0);
	window->CenterWindow();
	window->ShowWindow();
}

bool MonkeySerForm::OnNotify(ui::EventArgs * msg)
{
	std::wstring name = msg->pSender->GetName();

	if (msg->Type == ui::kEventClick)
	{
		if (name == L"addbtn")
		{
			LOGNF("click add button, name:%ws\n", name.c_str());

			ui::ListContainerElement* element = new ui::ListContainerElement;
			element->SetText(nbase::StringPrintf(L" Group %d", m_group_list->GetCount()));
			element->SetClass(L"listitem");
			element->SetName(nbase::StringPrintf(L"group_item_%d", m_group_list->GetCount()));
			element->SetFixedHeight(40);
			m_group_list->Add(element);
			m_group_list->SelectItem(m_group_list->GetCount()-1, true);
		}
	}
	else if (msg->Type == ui::kEventMouseMenu)
	{
		if (name.find(L"group_item_") != -1)
		{
			auto mouse = msg->ptMouse;
			ui::CPoint point{ mouse.x, mouse.y };
			ClientToScreen(m_hWnd, &point);
			nim_comp::CMenuWnd* pMenu = new nim_comp::CMenuWnd(NULL);
			ui::STRINGorID xml(L"group_menu.xml");
			pMenu->Init(xml, _T("xml"), point);
			auto ele = (nim_comp::CMenuElementUI*)(pMenu->FindControl(L"start"));
			ele->AttachSelect(nbase::Bind(&MonkeySerForm::OnGroupMenu, this, std::placeholders::_1));
			ele = (nim_comp::CMenuElementUI*)(pMenu->FindControl(L"stop"));
			ele->AttachSelect(nbase::Bind(&MonkeySerForm::OnGroupMenu, this, std::placeholders::_1));
			ele = (nim_comp::CMenuElementUI*)(pMenu->FindControl(L"add"));
			ele->AttachSelect(nbase::Bind(&MonkeySerForm::OnGroupMenu, this, std::placeholders::_1));
			ele = (nim_comp::CMenuElementUI*)(pMenu->FindControl(L"remove"));
			ele->AttachSelect(nbase::Bind(&MonkeySerForm::OnGroupMenu, this, std::placeholders::_1));
			pMenu->Show();
		}
	}

	return true;
}

bool MonkeySerForm::OnGroupMenu(ui::EventArgs * msg) {
	std::wstring name = msg->pSender->GetName();

	LOGNF("OnGroupMenu recv: name:%ws\n", name.c_str());

	if (name == L"start")
	{

	}
	else if (name == L"stop")
	{

	}
	else if (name == L"add")
	{
		ListItem* item = new ListItem;
		ui::GlobalManager::FillBoxWithCache(item, L"monkey_service/listitem.xml");
		std::wstring name = L"CF";
		std::wstring cmd = nbase::StringPrintf(L"cmd -%d", m_service_list->GetCount());
		item->InitSubControls(name, cmd);
		m_service_list->Add(item);
	}
	else if (name == L"remove")
	{

	}

	return false;
}