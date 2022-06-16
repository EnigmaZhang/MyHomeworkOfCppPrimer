#include <iostream>

#include <vector>
#include <algorithm>
#include <memory>

std::shared_ptr<std::vector<int>> getVector();
void fillVector(std::vector<int>& v);
void printVector(const std::vector<int>& v);

int main()
{
	auto p{ getVector()};
	fillVector(*p);
	printVector(*p);

	return 0;
}

std::shared_ptr<std::vector<int>> getVector()
{
	return std::make_shared<std::vector<int>>();
}

void fillVector(std::vector<int>& v)
{
	int n;
	while (std::cin >> n)
	{
		v.push_back(n);
	}
}

void printVector(const std::vector<int>& v)
{
	std::for_each(v.cbegin(), v.cend(), [](int n) { std::cout << n << ' '; });
	std::cout << std::endl;
}