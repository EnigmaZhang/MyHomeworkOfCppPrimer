#include <string>
#include <iostream>

class HasPtr
{
public:
	HasPtr(const std::string& s = std::string()) :
		ps{ new std::string{s} }, i{ 0 }, use{ new std::size_t{1} } {}

	HasPtr(const HasPtr& origin):
		ps{ origin.ps }, i{ origin.i }, use{ origin.use } 
	{
		++* use;
	}

	HasPtr& operator=(const HasPtr& origin)
	{
		++* origin.use;

		if (-- * use == 0)
		{
			delete ps;
			delete use;
		}
		ps = origin.ps;
		i = origin.i;
		use = origin.use;
		return *this;
	}

	~HasPtr()
	{
		if (-- * use == 0)
		{
			delete ps;
			delete use;
		}
	}

	std::size_t get_use() { return *use; }
private:
	std::string* ps;
	int i;
	std::size_t* use;
};

int main()
{
	HasPtr p1{ "aaa" };
	HasPtr p2{ p1 };
	HasPtr p3{ "bbb" };
	HasPtr p4{ p3 };
	p3 = p1;

	std::cout << p1.get_use() << std::endl;
	std::cout << p2.get_use() << std::endl;
	std::cout << p3.get_use() << std::endl;
	std::cout << p4.get_use() << std::endl;


	return 0;
}