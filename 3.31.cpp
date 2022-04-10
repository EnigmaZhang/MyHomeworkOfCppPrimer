#include <iostream>

int main()
{
	constexpr size_t size{ 10 };
	int a[size];

	for (size_t i{ 0 }; i < size; i++)
	{
		a[i] = static_cast<int>(i);
	}

	for (auto i : a)
	{
		std::cout << i << std::endl;
	}

	return 0;
}