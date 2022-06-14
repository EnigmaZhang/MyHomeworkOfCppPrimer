#include <iostream>
#include <map>
#include <string>

int main()
{
	std::map<std::string, int> m{ {"Hello", 1},{"Good", 2} };

	for (auto iter{ m.begin() }; iter != m.end(); ++iter)
	{
		if (iter->first == "Good")
		{
			iter->second = 3;
			break;
		}
	}
	std::cout << m["Good"] << std::endl;

	return 0;
}