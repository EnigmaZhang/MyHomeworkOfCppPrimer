#include <iostream>

class X;
class Y;

class X 
{
public:
	Y* y;
	int n{ 42 };
};

class Y
{
public:
	X x;
	double pi{ 3.14 };
};

int main()
{
	X x = X();
	Y y = Y();
	x.y = &y;
	y.x = x;
	std::cout << x.y->pi << std::endl;
	std::cout << y.x.n << std::endl;

	return 0;
}
