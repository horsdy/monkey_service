#pragma once
#include "stdafx.h"

class ListProvider : public ui::VirtualListInterface
{
public:
	ListProvider();
	~ListProvider();

	/**
	* @brief 创建一个子项
	* @return 返回创建后的子项指针
	*/
	virtual ui::Control* CreateElement() override;

	/**
	* @brief 填充指定子项
	* @param[in] control 子项控件指针
	* @param[in] index 索引
	* @return 返回创建后的子项指针
	*/
	virtual void FillElement(ui::Control *control, int index) override;

	/**
	* @brief 获取子项总数
	* @return 返回子项总数
	*/
	virtual int GetElementtCount() override;

	/**
	* @brief 增加子项总数
	* @return 返回子项总数
	*/
	int AddElementCount(int);
private:
	int m_count;
};

