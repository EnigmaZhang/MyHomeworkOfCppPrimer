#include <iostream>

int main()
{	
	std::cout << static_cast<char>((~static_cast<char>('q') << 6)) << std::endl;

	return 0;
}
