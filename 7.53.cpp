#include <iostream>
#include "Debug.h"

int main()
{
	constexpr Debug io_sub{ false, true, false };

	std::cout << io_sub.any() << std::endl;

	return 0;
}
