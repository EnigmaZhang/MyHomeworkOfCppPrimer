#include <iostream>
#include "Person.h"

int main()
{
	Person person = Person();
	person.name = "Ellery";
	person.address = "Shenzhen";

	std::cout << person.getName() << '\t' << person.getAddress() << std::endl;

	return 0;
}
