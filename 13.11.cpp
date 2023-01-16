#include <string>
#include <iostream>

void fun();

class HasPtr 
{
public:
	HasPtr(const std::string& s = std::string()) :
		ps(new std::string(s)), i(0) {}

	HasPtr(const HasPtr& origin) 
	{
		ps = new std::string(*origin.ps);
		i = origin.i;
	}

	HasPtr& operator=(const HasPtr& origin)
	{
		this->ps = new std::string(*origin.ps);
		i = origin.i;

		return *this;
	}

	~HasPtr()
	{
		std::cout << "string " + (*this->ps) + " will be destoyed" << std::endl;
		delete ps;
	}
	
	std::string* get_ps() { return ps; }
	int get_i() { return i; }
private:
	std::string* ps;
	int i;
};


void fun()
{
	HasPtr p1{ HasPtr(std::string("abc")) };
}

int main()
{
	fun();

	return 0;
}