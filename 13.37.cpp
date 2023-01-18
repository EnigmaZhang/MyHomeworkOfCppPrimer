#include <string>
#include <iostream>

#include "Book_Keeping.h"

int main()
{
	Message m1{ "aaa" }, m2{ "bbb" };
	Folder f1, f2;
	
	m1.save(f1);
	m1.save(f2);
	m2.save(f1);

	Folder f3{ f1 };
	f3 = f2;

	return 0;
}