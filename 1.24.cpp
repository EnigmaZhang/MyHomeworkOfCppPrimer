#include <iostream>
#include <map>
#include <utility>
#include <string>

#include "Sales_item.h"

int main()
{
	Sales_item item;
	std::map<std::string, Sales_item> item_map;

	while (std::cin >> item)
	{
		if (item_map.find(item.isbn()) == item_map.end())
		{
			item_map.insert(std::pair<std::string, Sales_item>(item.isbn(), item));
		}
		else
		{
			item_map.at(item.isbn()) += item;
		}
	}

	for (auto item_pair : item_map)
	{
		std::cout << item_pair.first << " : " << item_pair.second << std::endl;
	}

	return 0;
}