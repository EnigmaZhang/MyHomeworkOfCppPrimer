#include <iostream>
#include <string>

std::string global_str;
int global_int;

std::string boolToString(const bool i);

int main()
{
	// uninitialized
	//int local_int;
	//std::cout << local_int << std::endl;

	std::string local_str;

	std::cout << boolToString(global_str.empty()) << std::endl;
	std::cout << boolToString(global_int == 0) << std::endl;
	std::cout << boolToString(local_str.empty()) << std::endl;

	return 0;
}

std::string boolToString(const bool i)
{
	return i ? "true" : "false";
}
