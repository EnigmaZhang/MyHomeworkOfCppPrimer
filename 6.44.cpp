#include <iostream>
#include <string>

inline bool isShorter(const std::string& s1, const std::string& s2);

int main()
{
	std::cout << isShorter("Hello", "Hellos");

	return 0;
}

inline bool isShorter(const std::string& s1, const std::string& s2)
{
	return s1.size() < s2.size();
}