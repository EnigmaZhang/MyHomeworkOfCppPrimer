#include <iostream>
#include <string>

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
	auto s{ p(std::cin) };
	std::cout << s << std::endl;

	return 0;
}