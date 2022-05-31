#include <iostream>
#include <list>
#include <string>

int main()
{
	std::list<std::string> ls;
	std::string s;

	while (std::cin >> s)
	{
		ls.push_back(s);
	}

	for (auto iter{ ls.cbegin() }; iter != ls.cend(); ++iter)
	{
		std::cout << *iter << std::endl;
	}

	return 0;
}