#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	if (argc == 3)
	{
		std::cout << std::string(argv[1]) + std::string(argv[2]) << std::endl;
	}

	return 0;
}
