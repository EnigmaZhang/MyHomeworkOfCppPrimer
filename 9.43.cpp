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

	for (auto iter{ s.cbegin() }; iter <= (s.cend() - old_val.length()); )
	{
		if (old_val == std::string(iter, iter + old_val.length()))
		{
			iter = s.erase(iter, iter + old_val.size());
			iter = s.insert(iter, new_val.cbegin(), new_val.cend());
			iter += new_val.length();
		}
		else
		{
			++iter;
		}
	}
}
