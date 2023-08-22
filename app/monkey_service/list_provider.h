#pragma once
#include "stdafx.h"

class ListProvider : public ui::VirtualListInterface
{
public:
	ListProvider();
	~ListProvider();

	/**
	* @brief ����һ������
	* @return ���ش����������ָ��
	*/
	virtual ui::Control* CreateElement() override;

	/**
	* @brief ���ָ������
	* @param[in] control ����ؼ�ָ��
	* @param[in] index ����
	* @return ���ش����������ָ��
	*/
	virtual void FillElement(ui::Control *control, int index) override;

	/**
	* @brief ��ȡ��������
	* @return ������������
	*/
	virtual int GetElementtCount() override;

	/**
	* @brief ������������
	* @return ������������
	*/
	int AddElementCount(int);
private:
	int m_count;
};

