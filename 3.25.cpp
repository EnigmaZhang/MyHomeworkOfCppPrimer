#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v{ 42,65,95,100,39,67,95,76,88,76,83,92,76,93 };
	std::vector<int> grades(11, 0);
	
	for (auto iter{ v.cbegin() }; iter != v.cend(); iter++)
	{
		*(grades.begin() + *iter / 10) += 1;
	}

	for (auto iter{ grades.cbegin() }; iter != grades.cend(); iter++)
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;

	return 0;
}