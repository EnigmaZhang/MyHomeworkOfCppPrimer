#include <iostream>

int size{ -10 };

int get_size();

int main()
{
	for (auto sz{ get_size() }; sz <= 0; sz=get_size())
	{
		std::cout << sz << std::endl;
	}
	return 0;
}

int get_size()
{
	++size;
	return size;
}