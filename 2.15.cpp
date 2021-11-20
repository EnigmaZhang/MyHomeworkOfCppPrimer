#include <iostream>

int main()
{
	// int ival = 1.01;
	int ival{ static_cast<int>(1.01) };

	// illegal
	// int &rval1 = 1.01;

	int& rval2 = ival;

	// must init
	// int &rval3;

	return 0;
}
