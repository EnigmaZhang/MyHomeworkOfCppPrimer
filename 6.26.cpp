#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	for (int i{ 1 }; i < argc; ++i)
    {
        std::cout << std::string(argv[i]) << std::endl;
    }

	return 0;
}