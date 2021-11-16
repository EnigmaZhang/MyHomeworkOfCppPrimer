#include <iostream>
#include <vector>
#include <set>

int main()
{
	int currVal{ 0 }, val{ 0 };
	std::vector<int> v;

	if (std::cin >> currVal)
	{
		v.push_back(currVal);
		int cnt{ 1 };
		while (std::cin >> val)
		{
			v.push_back(val);
			if (val == currVal)
			{
				cnt++;
			}
			else
			{
				std::cout << currVal << " occurs "
					<< cnt << " times" << std::endl;
				currVal = val;
				cnt = 1;
			}
		}

		std::cout << currVal << " occurs "
			<< cnt << " times" << std::endl;
	}

	std::set<int> s = std::set<int>(v.begin(), v.end());

	if (v.empty())
	{
		std::cout << "No number input" << std::endl;
	}
	else 
	{
		if (s.size() == 1)
		{
			std::cout << "All numbers are equal" << std::endl;
			std::cout << v.at(0) << " occurs "
				<< v.size() << " times" << std::endl;
		}

		if (s.size() == v.size())
		{
			std::cout << "No numbers are repeated" << std::endl;
			for (int i : v)
			{
				std::cout << i << " occurs "
					<< 1 << " times" << std::endl;
			}
		}
	}

	return 0;
}