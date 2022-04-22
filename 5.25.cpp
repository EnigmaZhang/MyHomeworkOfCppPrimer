#include <iostream>
#include <stdexcept>

int main()
{
	int a, b;

	while (true)
	{
		try
		{
			std::cin >> a >> b;
			if (b == 0)
			{
				throw std::runtime_error("A number divided by zero");
			}
			std::cout << a / static_cast<double>(b) << std::endl;
			break;
		}
		catch (const std::runtime_error& e)
		{
			char c;

			std::cout << "Exception: " << e.what() << std::endl;
			std::cout << "Input a new group of numbers? Y or N" << std::endl;
			std::cin >> c;
			if (c == 'Y')
			{
				continue;
			}
			else
			{
				break;
			}
		}
	}
	
	return 0;
}