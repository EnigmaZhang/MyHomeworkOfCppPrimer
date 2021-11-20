#include <iostream>

int main()
{
	// single statement to declare
	// std::cin >> int input_value;

	int input_value;
	std::cin >> input_value;
	std::cout << input_value << std::endl;
	
	// wrong type
	// int i = { 3.14 };
	double i{ 3.14 };
	std::cout << i << std::endl;

	// wrong syntax
	// double salary = wage = 9999.99;
	double salary;
	double wage;
	salary = wage = 9999.99;

	// right, but i = 3
	//int i = 3.14;
	//std::cout << i << std::endl;
	int a{ static_cast<int>(3.14) };
	std::cout << a << std::endl;

	return 0;
}
