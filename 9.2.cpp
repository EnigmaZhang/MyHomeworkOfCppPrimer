#include <iostream>
#include <deque>
#include <list>

int main()
{
	std::list<std::deque<int>> l;

	std::deque<int> d;
	d.push_back(1);
	l.push_back(d);
	std::cout << l.back().back() << std::endl;

	return 0;
}