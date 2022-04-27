#include <iostream>

void print(const int* p);
void print(const int& i);
void print(const int* begin, const int* end);
void print(const int p[], size_t size);
void print(int (&arr)[2]);

int main()
{
	int i{ 0 }, j[2]{ 0,1 };

	print(i);
	print(&i);
	print(std::begin(j), std::end(j));
	print(j, std::end(j) - std::begin(j));
	print(j);

	return 0;
}

void print(const int* p)
{
	std::cout << *p << std::endl;
}

void print(const int& i)
{
	std::cout << i << std::endl;
}

void print(const int* begin, const int* end)
{
	for (auto p{ begin }; p != end; ++p)
	{
		std::cout << *p << '\t';
	}
	std::cout << std::endl;
}

void print(const int p[], size_t size)
{
	for (size_t i{ 0 }; i < size; ++i)
	{
		std::cout << p[i] << '\t';
	}
	std::cout << std::endl;
}

void print(int(&arr)[2])
{
	for (auto i : arr)
	{
		std::cout << i << '\t';
	}
	std::cout << std::endl;
}