#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template <typename T>
class EqualFunction
{
public:
	EqualFunction(T a) :a{ a } {}

	bool operator()(T b) const
	{
		return a == b;
	}
private:
	T a;
};

int main()
{
	std::vector<std::string> v{ "aaa", "bbb", "aaa", "ccc" };

	std::replace_if(v.begin(), v.end(), EqualFunction<std::string>("aaa"), "xxx");

	std::for_each(v.cbegin(), v.cend(), [&](std::string s) {std::cout << s << std::endl; });

	return 0;
}