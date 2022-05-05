#include <iostream>
#include <vector>

int add(int a, int b);

int sub(int a, int b);

int multiple(int a, int b);

int divide(int a, int b);

int main()
{
	std::vector<int (*) (int, int)> v{ add,sub,multiple,divide };

	for (auto f : v)
	{
		std::cout << f(3, 1) << std::endl;
	}

	return 0;
}

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int multiple(int a, int b)
{
	return a * b;
}

int divide(int a, int b)
{
	return a / b;
}
