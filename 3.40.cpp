#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

int main()
{
	char a[]{ "Hello " }, b[]{ "World!" };
	char c[1024];

	strcpy(c, a);
	strcat(c, b);

	std::cout << c << std::endl;

	return 0;
}
