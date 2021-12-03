#include <iostream>

int main()
{
	// not init
	// const int buf;

	int cnt{ 0 };
	const int sz{ cnt };
	++cnt;

	// modify const
	// ++sz;

	return 0;
}