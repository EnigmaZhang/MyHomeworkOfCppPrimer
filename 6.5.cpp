#include <iostream>

int abs(int n);

int main()
{
	std::cout << abs(0) << '\t' << abs(99) << '\t' << abs(-10) << std::endl;
	
	return 0;
}

int abs(int n)
{
	return n < 0 ? -n : n;
}