#include <iostream>
#include <limits>
#include <vector>
#include <string>

#include "Sales_item.h"

int main()
{

	std::cout << "int" << " has " << sizeof(int) << " bytes, "
		<< "max: " << std::numeric_limits<int>::max() << " min: " << std::numeric_limits<int>::min() << std::endl;

	std::cout << "unsinged int" << " has " << sizeof(unsigned int) << " bytes, "
		<< "max: " << std::numeric_limits<unsigned int>::max() << " min: " << std::numeric_limits<unsigned int>::min() << std::endl;

	std::cout << "long" << " has " << sizeof(long) << " bytes, "
		<< "max: " << std::numeric_limits<long>::max() << " min: " << std::numeric_limits<long>::min() << std::endl;

	std::cout << "unsigned long" << " has " << sizeof(unsigned long) << " bytes, "
		<< "max: " << std::numeric_limits<unsigned long>::max() << " min: " << std::numeric_limits<unsigned long>::min() << std::endl;

	std::cout << "long long" << " has " << sizeof(long long) << " bytes, "
		<< "max: " << std::numeric_limits<long long>::max() << " min: " << std::numeric_limits<long long>::min() << std::endl;

	std::cout << "unsigned long long" << " has " << sizeof(unsigned long long) << " bytes, "
		<< "max: " << std::numeric_limits<unsigned long long>::max() << " min: " << std::numeric_limits<unsigned long long>::min() << std::endl;

	std::cout << "short" << " has " << sizeof(short) << " bytes, "
		<< "max: " << std::numeric_limits<short>::max() << " min: " << std::numeric_limits<short>::min() << std::endl;

	std::cout << "unsigned short" << " has " << sizeof(unsigned short) << " bytes, "
		<< "max: " << std::numeric_limits<unsigned short>::max() << " min: " << std::numeric_limits<unsigned short>::min() << std::endl;

	std::cout << "float" << " has " << sizeof(float) << " bytes, "
		<< "max: " << std::numeric_limits<float>::max() << " min: " << std::numeric_limits<float>::min() << std::endl;

	std::cout << "double" << " has " << sizeof(double) << " bytes, "
		<< "max: " << std::numeric_limits<double>::max() << " min: " << std::numeric_limits<double>::min() << std::endl;

	std::cout << "char" << " has " << sizeof(char) << " bytes, "
		<< "max: " << static_cast<int>(std::numeric_limits<char>::max()) << " min: " << static_cast<int>(std::numeric_limits<char>::min()) << std::endl;

	std::cout << "unsigned char" << " has " << sizeof(unsigned char) << " bytes, "
		<< "max: " << static_cast<int>(std::numeric_limits<unsigned char>::max()) << " min: " << static_cast<int>(std::numeric_limits<unsigned char>::min()) << std::endl;

	std::cout << "signed char" << " has " << sizeof(signed char) << " bytes, "
		<< "max: " << static_cast<int>(std::numeric_limits<signed char>::max()) << " min: " << static_cast<int>(std::numeric_limits<signed char>::min()) << std::endl;

	std::cout << "bool" << " has " << sizeof(bool) << " bytes, "
		<< "max: " << std::numeric_limits<bool>::max() << " min: " << std::numeric_limits<bool>::min() << std::endl;

	return 0;
}