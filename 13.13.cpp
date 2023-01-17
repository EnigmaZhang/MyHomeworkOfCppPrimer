#include <string>
#include <vector>
#include <iostream>

struct X
{
	X()
	{
		std::cout << "X()" << std::endl;
	}

	X(const X&)
	{
		std::cout << "X(const X&)" << std::endl;
	}

	X& operator=(const X&)
	{
		std::cout << "X& operator=(const X&)" << std::endl;
		return *this;
	}

	~X()
	{
		std::cout << "~X()" << std::endl;
	}
};

void fun(X x1, X& x2);

int main()
{
	X x = X();
	X* x2 = new X();

	fun(x, x);

	std::vector<X> x_vector = std::vector<X>();
	
	// first copy
	x_vector.push_back(x);
	// size to 2, and copy old, copy new, and destroy old
	x_vector.push_back(x);
	// size to 2, and copy old, copy new, and destroy old
	x_vector.push_back(*x2);

	delete x2;

	return 0;
}

void fun(X x1, X& x2)
{
	x1 = x2;
	return;
}
