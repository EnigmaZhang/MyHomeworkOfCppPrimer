#include <iostream>
#include <deque>
#include <string>

int main()
{
	std::deque<std::string> dq;
	std::string s;

	while (std::cin >> s)
	{
		dq.push_back(s);
	}

	for (auto iter{ dq.cbegin() }; iter != dq.cend(); ++iter)
	{
		std::cout << *iter << std::endl;
	}

	return 0;
}