#pragma once

// �� ui::ListContainerElement �м̳����п��ù���
class ListItem : public ui::ListContainerElement
{
public:
	ListItem();
	~ListItem();

	// �ṩ�ⲿ��������ʼ�� item ����
	void InitSubControls(const std::wstring& img, const std::wstring& title, int nDataIndex);
private:
	bool OnRemove(ui::EventArgs* args);
	ui::Label* m_ser_name_label;
	ui::Label* m_ser_cmd_label;
};
