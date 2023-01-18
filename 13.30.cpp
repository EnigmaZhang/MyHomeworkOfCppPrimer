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

	HasPtr& operator=(HasPtr origin);

	friend void swap(HasPtr&, HasPtr&);

	std::string* get_ps() { return ps; }
	int get_i() { return i; }

private:
	std::string* ps;
	int i;
};

inline
void swap(HasPtr& lhs, HasPtr& rhs)
{
	std::cout << "swap between HasPtr happens" << std::endl;
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}

HasPtr& HasPtr::operator=(HasPtr origin)
{
	swap(*this, origin);

	return *this;
}

int main()
{
	HasPtr p1{ "aaa" };
	HasPtr p2{ "bbb" };
	p2 = p1;
	swap(p1, p2);

	return 0;
}