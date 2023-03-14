#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class StringLengthMatcher
{
public:
	StringLengthMatcher(std::string::size_type l, std::string::size_type h) :l{ l }, h{ h } {}
	bool operator()(std::string& s) { return s.length() >= l && s.length() <= h; }
private:
	std::string::size_type l;
	std::string::size_type h;
};

int main()
{
	std::vector<std::string> v{ "aaa", "bbb", "aaa", "ccc", "", "aaaaaaaaaaaaaaaaa" };
	std::vector<std::string> o;

	std::ranges::copy_if(v, std::back_inserter(o), StringLengthMatcher(1, 10));

	std::cout << "1-10: " << o.size() << std::endl;

	return 0;
}