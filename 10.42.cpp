#include <iostream>
#include <string>
#include <list>
#include <algorithm>

void elimDups(std::list<std::string>& ls);

int main()
{
	std::list<std::string> ls{ "aaa", "bbb", "abcd", "aaa" };
	elimDups(ls);
	std::for_each(ls.cbegin(), ls.cend(), [](std::string s) {std::cout << s << ' '; });
	std::cout << std::endl;

	return 0;
}



void elimDups(std::list<std::string>& ls)
{
	ls.sort();
	ls.unique();
}