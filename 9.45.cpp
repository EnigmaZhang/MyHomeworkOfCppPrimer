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
	ret.insert(ret.cbegin(), ' ');
	ret.insert(ret.cbegin(), prefix.cbegin(), prefix.cend());
	ret.append(" ").append(suffix);

	return ret;
}
