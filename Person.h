#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
public:
	std::string name;
	std::string address;

	std::string getName() const { return name; }
	std::string getAddress() const { return address; }
};

#endif
