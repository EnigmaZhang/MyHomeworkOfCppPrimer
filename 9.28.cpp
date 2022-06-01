#include <iostream>
#include <forward_list>
#include <string>

void find_and_insert(std::forward_list<std::string>& ls, const std::string& to_find, const std::string& to_insert);

int main()
{
	std::forward_list<std::string > fl{ "aaa", "bbb" };
	find_and_insert(fl, "aaa", "xxx");
	for (auto s : fl)
	{
		std::cout << s << std::endl;
	}
	std::cout << std::endl;

	fl.clear();
	find_and_insert(fl, "aaa", "xxx");
	for (auto s : fl)
	{
		std::cout << s << std::endl;
	}
	
	return 0;
}

void find_and_insert(std::forward_list<std::string>& ls, const std::string& to_find, const std::string& to_insert)
{
	auto  prev{ ls.cbefore_begin() }, curr{ ls.cbegin() };
	while (curr != ls.cend())
	{
		if (*curr == to_find)
		{
			ls.insert_after(curr, to_insert);
			return;
		}
		else
		{
			prev = curr;
			++curr;
		}
	}
	ls.insert_after(prev, to_insert);

}