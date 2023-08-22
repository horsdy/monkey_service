#include "stdafx.h"
#include "list_provider.h"
#include "list_item.h"

ListProvider::ListProvider() : m_count(0)
{

}

ListProvider::~ListProvider() = default;

ui::Control* ListProvider::CreateElement()
{
	ListItem* item = new ListItem;
	ui::GlobalManager::FillBoxWithCache(item, L"layouts/listitem.xml");
	return item;
}

void ListProvider::FillElement(ui::Control *control, int index)
{
	ListItem* pItem = dynamic_cast<ListItem*>(control);

	std::wstring name = L"CF";
	std::wstring cmd = nbase::StringPrintf(L"cmd -%d", index);
	pItem->InitSubControls(name, cmd, index);
}

int ListProvider::GetElementtCount()
{
	return m_count;
}

int ListProvider::AddElementCount(int n)
{
	m_count += n;
	return m_count;
}