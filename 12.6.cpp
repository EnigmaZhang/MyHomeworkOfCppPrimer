#include <iostream>

#include <vector>
#include <algorithm>

std::vector<int>* getVector();
std::vector<int>* fillVector(std::vector<int>& v);
std::vector<int>* printVector(std::vector<int>& v);

int main()
{
	auto p{ getVector()};
	p = fillVector(*p);
	p = printVector(*p);
	delete p;
	p = nullptr;

	return 0;
}

std::vector<int>* getVector()
{
	return new std::vector<int>();
}

std::vector<int>* fillVector(std::vector<int>& v)
{
	int n;
	while (std::cin >> n)
	{
		v.push_back(n);
	}
	return &v;
}

std::vector<int>* printVector(std::vector<int>& v)
{
	std::for_each(v.cbegin(), v.cend(), [](int n) { std::cout << n << ' '; });
	std::cout << std::endl;
	return &v;
}