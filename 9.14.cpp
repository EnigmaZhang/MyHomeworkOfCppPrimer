#include <iostream>
#include <vector>
#include <list>
#include <string>

int main()
{
	char s1[]{"Hello"};
	char s2[]{ "World!" };
	std::list<char*> l{ s1,s2 };
	std::vector<std::string> v;

	v.assign(l.cbegin(), l.cend());
	for (auto s : v)
	{
		std::cout << s << std::endl;
	}
	
	return 0;
}