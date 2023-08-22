#include "stdafx.h"
#include "list_item.h"

ListItem::ListItem()
{

}

ListItem::~ListItem()
= default;

void ListItem::InitSubControls(const std::wstring& name, const std::wstring& cmd)
{
	if (m_ser_name_label == nullptr) {
		m_ser_name_label = dynamic_cast<ui::Label*>(FindSubControl(L"ser_name_label"));
		m_ser_cmd_label = dynamic_cast<ui::Label*>(FindSubControl(L"ser_cmd_label"));
	}
	// 设置服务名称
	m_ser_name_label->SetText(name);
	// 设置服务命令
	m_ser_cmd_label->SetText(cmd);
}

bool ListItem::OnRemove(ui::EventArgs* args)
{
	return true;
}