#include <iostream>
#include <vector>

int takeTwoInt(int a, int b);

int main()
{
	std::vector<int (*) (int, int)> v;
	v.push_back(takeTwoInt);
	std::cout << v[0](1, 2) << std::endl;

	return 0;
}

int takeTwoInt(int a, int b)
{
	return a + b;
}
