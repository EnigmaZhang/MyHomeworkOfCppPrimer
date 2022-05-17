#include <iostream>

class NoDefault
{
public:
	int n;
	NoDefault(int n) :n(n) {}
};

class C
{
public:
	NoDefault noDefault;
	C() :noDefault(NoDefault(0)) {}
};

int main()
{
	C c;
	std::cout << c.noDefault.n << std::endl;

	return 0;
}
