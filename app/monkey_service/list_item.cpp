#include "stdafx.h"
#include "list_item.h"

ListItem::ListItem()
{

}

ListItem::~ListItem()
= default;

void ListItem::InitSubControls(const std::wstring& name, const std::wstring& cmd)
{
	m_ser_name_label = dynamic_cast<ui::Label*>(FindSubControl(L"ser_name_label"));
	m_ser_cmd_label = dynamic_cast<ui::Label*>(FindSubControl(L"ser_cmd_label"));
	m_ser_start_btn = dynamic_cast<ui::Button*>(FindSubControl(L"ser_start_btn"));

	// ���÷�������
	m_ser_name_label->SetText(name);
	// ���÷�������
	m_ser_cmd_label->SetText(cmd);

	// ������/ֹͣ������
	m_ser_start_btn->AttachClick(nbase::Bind(&ListItem::OnSwitch, this, std::placeholders::_1));
}

bool ListItem::OnSwitch(ui::EventArgs* args)
{
	std::wstring name = args->pSender->GetName();

	//m_ser_start_btn->SetBkImage();
	LOGNF("recv: name:%ws\n", name)

	return true;
}


bool ListItem::OnRemove(ui::EventArgs* args)
{
	ui::ListBox* parent = dynamic_cast<ui::ListBox*>(this->GetParent());
	return parent->Remove(this);
}