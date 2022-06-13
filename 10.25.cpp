#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

std::string make_plural(size_t ctr, const std::string& word, const std::string& ending = "s");
void elimDups(std::vector<std::string>& v);
void biggies(std::vector<std::string>& words, std::vector<std::string>::size_type sz);
bool checkSize(const std::string& s, std::string::size_type sz);

int main()
{
	std::vector<std::string> v{ "Hello", "me", "Where", "abc" };
	biggies(v, 3);

	return 0;
}

void biggies(std::vector<std::string>& words, std::vector<std::string>::size_type sz)
{
	elimDups(words);

	auto wc{ std::find_if(words.begin(), words.end(),
		std::bind(checkSize, std::placeholders::_1, sz))};
	auto count{ words.end() - wc};
	std::cout << count << " " << make_plural(count, "word") << " of length " << sz << " or longer" << std::endl;
	std::for_each(wc, words.end(),
		[](const std::string& s) {std::cout << s << " "; });
	std::cout << std::endl;
}

void elimDups(std::vector<std::string>& v)
{
	std::sort(v.begin(), v.end());

	auto end_unique = std::unique(v.begin(), v.end());

	v.erase(end_unique, v.end());
}

std::string make_plural(size_t ctr, const std::string& word, const std::string& ending)
{
	return (ctr > 1) ? word + ending : word;
}

bool checkSize(const std::string& s, std::string::size_type sz)
{
	return s.length() >= sz;
}