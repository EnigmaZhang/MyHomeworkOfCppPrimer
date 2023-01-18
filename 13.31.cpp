#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

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
	bool operator<(const HasPtr& rhs) const;

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

bool HasPtr::operator<(const HasPtr& rhs) const
{
	return *(this->ps) < *(rhs.ps);
}

int main()
{
	HasPtr p1{ "Hello" }, p2{ "abcd" }, p3{ "Hell" }, p4{ "Hella" };
	std::vector<HasPtr> v{ p1,p2,p3,p4 };
	std::sort(v.begin(), v.end());
	for (auto p : v)
	{
		std::cout << *p.get_ps() << std::endl;
	}

	return 0;
}