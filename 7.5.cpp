#include <iostream>
#include "Person.h"

int main()
{
	Person person = Person("Ellery", "Shenzhen");

	std::cout << person.getName() << '\t' << person.getAddress() << std::endl;

	return 0;
}
