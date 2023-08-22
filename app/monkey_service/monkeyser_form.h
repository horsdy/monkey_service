#pragma once

class MonkeySerForm : public ui::WindowImplBase
{
public:
	MonkeySerForm(const std::wstring& class_name, const std::wstring& theme_directory, const std::wstring& layout_xml);
	~MonkeySerForm();

	/**
	 * һ�������ӿ��Ǳ���Ҫ��д�Ľӿڣ����������������ӿ�����������
	 * GetSkinFolder		�ӿ�������Ҫ���ƵĴ���Ƥ����Դ·��
	 * GetSkinFile			�ӿ�������Ҫ���ƵĴ��ڵ� xml �����ļ�
	 * GetWindowClassName	�ӿ����ô���Ψһ��������
	 */
	virtual std::wstring GetSkinFolder() override;
	virtual std::wstring GetSkinFile() override;
	virtual std::wstring GetWindowClassName() const override;

	/**
	 * �յ� WM_CREATE ��Ϣʱ�ú����ᱻ���ã�ͨ����һЩ�ؼ���ʼ���Ĳ���
	 */
	virtual void InitWindow() override;

	/**
	 * �յ� WM_CLOSE ��Ϣʱ�ú����ᱻ����
	 */
	virtual LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);


public:
	static void ShowCustomWindow(const std::wstring& class_name, const std::wstring& theme_directory, const std::wstring& layout_xml);
	bool MonkeySerForm::OnNotify(ui::EventArgs * msg);
	bool MonkeySerForm::OnGroupMenu(ui::EventArgs * msg);

private:
	std::wstring m_class_name;
	std::wstring m_theme_directory;
	std::wstring m_layout_xml;

	ui::ListBox* m_group_list;
	ui::ListBox* m_service_list;
};

