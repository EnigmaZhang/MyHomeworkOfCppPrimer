#include <iostream>
#include <string>
#include <vector>

class PrintString
{
public:
	std::string operator()(std::istream& is) const
	{
		std::string s;
		std::getline(is, s);
		return is ? s : std::string();
	}
};

int main()
{
	PrintString p{ PrintString() };
	std::vector<std::string> v;

	while (std::cin)
	{
		v.push_back(p(std::cin));
	}

	for (auto s : v) {
		std::cout << s << std::endl;
	}

	return 0;
}