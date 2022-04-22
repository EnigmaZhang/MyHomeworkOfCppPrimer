#include <iostream>
#include <vector>

bool isPrefixVector(const std::vector<int>& v1, const std::vector<int>& v2);

int main()
{
	std::vector<int> v1, v2;
	int i;
	while (std::cin >> i)
	{
		char c;
		v1.push_back(i);
		std::cin.get(c);
		if (c == '\n')
		{
			break;
		}
	}

	while (std::cin >> i)
	{
		char c;
		v2.push_back(i);
		std::cin.get(c);
		if (c == '\n')
		{
			break;
		}
	}

	std::cout << isPrefixVector(v1, v2) << std::endl;

	return 0;
}


bool isPrefixVector(const std::vector<int>& v1, const std::vector<int>& v2)
{
	const std::vector<int>& smaller{ v1.size() < v2.size() ? v1 : v2 };
	const std::vector<int>& larger{ v1.size() < v2.size() ? v2 : v1 };

	for (auto i{ smaller.cbegin() }, j{ larger.cbegin() }; i != smaller.cend(); ++i, ++j)
	{
		if (*i != *j)
		{
			return false;
		}
	}

	return true;
}