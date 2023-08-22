#pragma once

// 从 ui::ListContainerElement 中继承所有可用功能
class ListItem : public ui::ListContainerElement
{
public:
	ListItem();
	~ListItem();

	// 提供外部调用来初始化 item 数据
	void InitSubControls(const std::wstring& img, const std::wstring& title);
private:
	bool OnRemove(ui::EventArgs* args);
	ui::Label* m_ser_name_label;
	ui::Label* m_ser_cmd_label;
};
