#include "stdafx.h"
#include "monkeyser_form.h"
#include "list_item.h"

MonkeySerForm::MonkeySerForm()
{
}

MonkeySerForm::~MonkeySerForm()
{
}

std::wstring MonkeySerForm::GetSkinFolder()
{
	return L"monkey_service";
}

std::wstring MonkeySerForm::GetSkinFile()
{
	return L"monkey_service.xml";
}

std::wstring MonkeySerForm::GetWindowClassName() const
{
	return L"Monkey Service";
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

bool MonkeySerForm::OnNotify(ui::EventArgs * msg)
{
	std::wstring name = msg->pSender->GetName();

	if (msg->Type == ui::kEventClick)
	{
		LOGNF("kEventClick, name:%ws\n", name.c_str());

		if (name == L"addbtn")
		{
			ui::ListContainerElement* element = new ui::ListContainerElement;
			element->SetText(nbase::StringPrintf(L" Group %d", m_group_list->GetCount()));
			element->SetClass(L"listitem");
			element->SetName(nbase::StringPrintf(L"group_item_%d", m_group_list->GetCount()));
			element->SetFixedHeight(40);
			m_group_list->Add(element);
			m_group_list->SelectItem(m_group_list->GetCount() - 1, true);
		}
		else if (name == L"ser_start_btn")
		{
			ui::Control* sender = msg->pSender;
			ui::Box* item = sender->GetParent()->GetParent();
			ui::Button* ser_stop_btn = dynamic_cast<ui::Button*>(item->FindSubControl(L"ser_stop_btn"));
			sender->SetVisible(false);
			ser_stop_btn->SetVisible(true);
			int index = m_service_list->GetItemIndex(item);
			m_service_list->SelectItem(index, true);
		}
		else if (name == L"ser_stop_btn")
		{
			ui::Control* sender = msg->pSender;
			ui::Box* item = sender->GetParent()->GetParent();
			ui::Button* ser_start_btn = dynamic_cast<ui::Button*>(item->FindSubControl(L"ser_start_btn"));
			sender->SetVisible(false);
			ser_start_btn->SetVisible(true);
			int index = m_service_list->GetItemIndex(item);
			m_service_list->SelectItem(index, true);
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

	LOGNF("OnGroupMenu name:%ws\n", name.c_str());

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
		std::wstring name = L"User";
		std::wstring cmd = L"echo hello";
		item->InitSubControls(name, cmd);
		item->SetName(nbase::StringPrintf(L"service_item_%d", m_service_list->GetCount()));
		m_service_list->Add(item);
	}
	else if (name == L"remove")
	{

	}

	return false;
}