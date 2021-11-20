#include <iostream>

int main()
{
	int i{ 0 }, & r1{ i };
	double d{ 0 }, & r2{ d };

	r2 = 3.14159;
	r2 = r1;
	i = static_cast<int>(r2);
	r1 = static_cast<int>(d);

	return 0;
}
