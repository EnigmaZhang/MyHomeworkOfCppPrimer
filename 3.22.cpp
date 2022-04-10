#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::vector<std::string> text;
	std::string word;

	while (std::getline(std::cin, word))
	{
		text.push_back(word);
	}

	for (auto v_iter{ text.begin() }; v_iter != text.end() && !v_iter->empty(); v_iter++)
	{
		for (auto s_iter{ v_iter->begin() }; s_iter != v_iter->end(); s_iter++)
		{
			*s_iter = static_cast<char>(toupper(*s_iter));
		}
	}

	for (auto v_iter{ text.begin() }; v_iter != text.end(); v_iter++)
	{
		std::cout << *v_iter << std::endl;
	}

	return 0;
}