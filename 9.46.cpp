#include <iostream>
#include <string>

std::string handle_name(const std::string& s, const std::string& prefix="", const std::string& suffix="");

int main()
{
	std::cout << handle_name("Zhang", "Mr.", "Jr") << std::endl;
	
	return 0;
}

std::string handle_name(const std::string& s, const std::string& prefix, const std::string& suffix)
{
	std::string ret{ s };
	ret.insert(0, " ");
	ret.insert(0, prefix);
	ret.insert(ret.length(), " ");
	ret.insert(ret.length(), suffix);

	return ret;
}
