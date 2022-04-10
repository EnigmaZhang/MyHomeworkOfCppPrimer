#include <iostream>
#include <vector>

int main()
{
	constexpr size_t size{ 10 };
	int a[size];
	int another[size];
	std::vector<int> v;

	for (size_t i{ 0 }; i < size; i++)
	{
		a[i] = static_cast<int>(i);
	}

	for (auto i : a)
	{
		std::cout << i << std::endl;
	}

	for (size_t i{ 0 }; i < size; i++)
	{
		another[i] = a[i];
		v.push_back(a[i]);
	}

	for (auto i : another)
	{
		std::cout << i << ' ';
	}
	std::cout << std::endl;

	for (auto i : v)
	{
		std::cout << i << ' ';
	}
	std::cout << std::endl;

	return 0;
}