#include <iostream>
#include <string>

void replace(std::string& s, const std::string& old_val, const std::string& new_val);

int main()
{
	std::string s{ "through one way through" };
	replace(s, "through", "thru");
	std::cout << s << std::endl;
	
	return 0;
}

void replace(std::string& s, const std::string& old_val, const std::string& new_val)
{
	if (old_val.empty() || s.empty())
	{
		return;
	}
	if (old_val == new_val)
	{
		return;
	}

	for (std::string::size_type index{ 0 }; index <= (s.length() - old_val.length()); )
	{
		if (old_val == s.substr(index, old_val.length()))
		{
			s.replace(index, old_val.length(), new_val);
		}
		else
		{
			++index;
		}
	}
}
