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

	HasPtr& operator=(HasPtr& origin);
	HasPtr(HasPtr&&) noexcept;
	HasPtr& operator=(HasPtr&&) noexcept;

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

HasPtr& HasPtr::operator=(HasPtr& origin)
{
	delete this->ps;
	this->ps = new std::string(*origin.ps);
	this->i = origin.i;

	return *this;
}

bool HasPtr::operator<(const HasPtr& rhs) const
{
	return *(this->ps) < *(rhs.ps);
}

HasPtr::HasPtr(HasPtr&& p) noexcept:
	ps{ p.ps }, i{ p.i }
{
	p.ps = nullptr;
	p.i = 0;
}

HasPtr& HasPtr::operator=(HasPtr&& rhs) noexcept
{
	if (this != &rhs)
	{
		delete this->ps;

		this->ps = rhs.ps;
		this->i = rhs.i;

		rhs.ps = nullptr;
		rhs.i = 0;
	}

	return *this;
}

int main()
{
	HasPtr p{ "aaa" };
	HasPtr p2;
	HasPtr p3;
	p3 = p;
	p2 = std::move(p);

	return 0;
}