#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ranges>

void biggie(std::vector<std::string>& words, std::string::size_type sz);

class LongerOrEqual
{
public:
	LongerOrEqual(std::string::size_type sz) :sz{ sz } {}

	bool operator()(std::string& s) const
	{
		return s.length() >= sz;
	}
private:
	std::string::size_type sz;
};


void biggie(std::vector<std::string>& words, std::string::size_type sz)
{
	std::vector<std::string> res;
	std::ranges::copy_if(words, std::back_inserter(res), LongerOrEqual(sz));
	std::cout << "num: " << res.size() << std::endl;
	std::ranges::for_each(res, [](std::string s) {std::cout << s << std::endl; });
}


int main()
{
	std::vector<std::string> v{ "aaa", "bbbb", "ccccc" };
	biggie(v, 4);

	return 0;
}