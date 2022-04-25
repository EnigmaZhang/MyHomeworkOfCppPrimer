#include <iostream>

int callTimes();

int main()
{
	std::cout << callTimes() << std::endl;
	std::cout << callTimes() << std::endl;
	std::cout << callTimes() << std::endl;
	std::cout << callTimes() << std::endl;

	return 0;
}

int callTimes()
{
	static int t{ 0 };
	return t++;
}
