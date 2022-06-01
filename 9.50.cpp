#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::vector<std::string> v1{ "1", "3", "5" };
	int int_sum{ 0 };
	for (auto s : v1)
	{
		int_sum += std::stoi(s);
	}
	std::cout << int_sum << std::endl;

	std::vector<std::string> v2{ "1.0", "3.14", "5.5" };
	double double_sum{ 0.0 };
	for (auto s : v2)
	{
		double_sum += std::stod(s);
	}
	std::cout << double_sum << std::endl;

	return 0;
}
