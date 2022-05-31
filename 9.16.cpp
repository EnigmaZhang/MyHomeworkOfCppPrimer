#include <iostream>
#include <vector>

bool vector_int_equal(const std::vector<int>& a, const std::vector<int>& b);

int main()
{
	std::vector<int> v1{ 1,2,3,4 };
	std::vector<int> v2{ 1,2,3 };
	std::vector<int> v3{ v1 };
	std::vector<int> v4{ 1,2,3,3 };

	std::cout << vector_int_equal(v1, v2) << std::endl;
	std::cout << vector_int_equal(v1, v3) << std::endl;
	std::cout << vector_int_equal(v1, v4) << std::endl;

	return 0;
}

bool vector_int_equal(const std::vector<int>& a, const std::vector<int>& b)
{
	if (a.size() != b.size())
	{
		return false;
	}
	for (auto x{ a.cbegin() }, y{ b.cbegin() }; x != a.cend() && y != b.cend(); ++x, ++y)
	{
		if (*x != *y)
		{
			return false;
		}
	}
	return true;
}