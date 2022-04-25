#include <iostream>

int fact(int n);

int main()
{
	std::cout << fact(5) << std::endl;
	
	return 0;
}

int fact(int n)
{
	int ret{ 1 };
	while (n > 1)
	{
		ret *= n--;
	}

	return ret;
}