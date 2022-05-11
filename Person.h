#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
private:
	std::string name;
	std::string address;
public:
	Person() = default;
	Person(const std::string& name, const std::string& address) :name(name), address(address) {};
	std::string getName() const { return name; }
	std::string getAddress() const { return address; }
};

#endif
