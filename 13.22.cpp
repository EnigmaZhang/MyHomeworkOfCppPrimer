#include <string>
#include <iostream>

class HasPtr
{
public:
	HasPtr(const std::string& s = std::string()) : ps{ new std::string{s} }, i(0) {}

	HasPtr(const HasPtr& origin)
	{
		ps = new std::string(*origin.ps);
		i = origin.i;
	}

	HasPtr& operator=(const HasPtr& origin)
	{
		auto newp{ new std::string{*origin.ps} };
		delete ps;
		ps = newp;
		i = origin.i;

		return *this;
	}

	std::string* get_ps() { return ps; }
	int get_i() { return i; }

private:
	std::string* ps;
	int i;
};

int main()
{
	HasPtr p1{ HasPtr{std::string{"abc"}} };
	HasPtr p2;
	p2 = p1;
	std::cout << (p1.get_ps() == p2.get_ps()) << std::endl;
	std::cout << (*p1.get_ps() == *p2.get_ps()) << std::endl;
	std::cout << (p1.get_i() == p2.get_i()) << std::endl;

	return 0;
}