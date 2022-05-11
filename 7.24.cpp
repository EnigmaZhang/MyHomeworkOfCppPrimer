#include <iostream>
#include "Screen.h"

int main()
{
	Screen screen = Screen(3, 4);
	for (unsigned int r{ 0 }, c{ 0 }; r < 3U && c < 4U; ++r, ++c)
	{
		std::cout << screen.get(r, c);
	}
	std::cout << std::endl;

	return 0;
}
