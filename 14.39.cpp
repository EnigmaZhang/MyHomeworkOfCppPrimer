#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ranges>
#include <limits>

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

	std::ranges::copy_if(v, std::back_inserter(o), StringLengthMatcher(1, 9));

	std::cout << "1-9: " << o.size() << std::endl;

	o.erase(o.begin(), o.end());
	std::ranges::copy_if(v, std::back_inserter(o),
		StringLengthMatcher(10, std::numeric_limits<std::string::size_type>::max()));
	std::cout << ">10: " << o.size() << std::endl;

	return 0;
}