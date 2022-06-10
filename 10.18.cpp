#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

std::string make_plural(size_t ctr, const std::string& word, const std::string& ending = "s");
void elimDups(std::vector<std::string>& v);
void biggies(std::vector<std::string>& words, std::vector<std::string>::size_type sz);

int main()
{
	std::vector<std::string> v{ "Hello", "me", "Where", "abc" };
	biggies(v, 3);

	return 0;
}

void biggies(std::vector<std::string>& words, std::vector<std::string>::size_type sz)
{
	elimDups(words);

	auto wc{ std::partition(words.begin(), words.end(),
		[sz](const std::string& s) {return s.size() >= sz; }) };
	std::sort(words.begin(), wc);
	auto count{ wc - words.cbegin() };
	std::cout << count << " " << make_plural(count, "word") << " of length " << sz << " or longer" << std::endl;
	std::for_each(words.begin(), wc,
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
