#ifndef NEW_STRING_H
#define NEW_STRING_H

#include <iostream>
#include <memory>
#include <algorithm>

class String
{
public:
	friend bool operator== (const String & lhs, const String & rhs);
	friend bool operator!= (const String& lhs, const String& rhs);
	friend bool operator<(const String& lhs, const String& rhs);
	friend bool operator<=(const String& lhs, const String& rhs);
	friend bool operator>(const String& lhs, const String& rhs);
	friend bool operator>=(const String& lhs, const String& rhs);


	String() :
		elements{ nullptr }, first_free{ nullptr }, cap{ nullptr } {}
	String(std::initializer_list<char>);
	String(const String&);
	String(const char*);
	String& operator=(const String&);
	~String();
	String(String&& s) noexcept;
	String& operator=(String&& rhs) noexcept;
	char operator[](size_t n) { return elements[n]; }
	const char operator[](size_t n) const { return elements[n]; }
	friend std::ostream& operator<<(std::ostream&, const String&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	void reserve(size_t);
	void resize(size_t n, const char& s);
	void push_back(const char&);
	void pop_back();
	char* begin() const { return elements; }
	char* end() const { return first_free; }
private:
	std::allocator<char> alloc;
	using alloc_traits_t = std::allocator_traits<decltype(alloc)>;

	void chk_n_alloc()
	{
		if (size() == capacity())
		{
			reallocate();
		}
	}
	std::pair<char*, char*> alloc_n_copy(const char*, const char*);
	void free();
	void reallocate();
	char* elements;
	char* first_free;
	char* cap;
};

String::String(const String& s)
{
	auto newdata{ alloc_n_copy(s.begin(), s.end()) };
	elements = newdata.first;
	first_free = cap = newdata.second;
}

String::String(std::initializer_list<char> ls) :
	elements{ nullptr }, first_free{ nullptr }, cap{ nullptr }
{
	auto newdata{ alloc_n_copy(ls.begin(), ls.end()) };
	elements = newdata.first;
	first_free = cap = newdata.second;
}

String::String(const char* s):
	elements{ nullptr }, first_free{ nullptr }, cap{ nullptr }
{
	while (s && *s != '\0')
	{
		push_back(*s++);
	}
}

String& String::operator=(const String& rhs)
{
	auto data{ alloc_n_copy(rhs.begin(), rhs.end()) };
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

String::~String()
{
	free();
}

std::pair<char*, char*>
String::alloc_n_copy(const char* b, const char* e)
{
	auto data{ alloc.allocate(e - b) };
	return { data, std::uninitialized_copy(b,e,data) };
}

void String::free()
{
	if (elements)
	{
		std::for_each(elements, first_free,
			[this](char p) { alloc_traits_t::destroy(this->alloc, &p); });
		alloc.deallocate(elements, cap - elements);
	}
}

void String::reallocate()
{
	auto newcapacity{ size() ? 2 * size() : 1 };
	auto newdata{ alloc.allocate(newcapacity) };
	auto dest{ newdata };
	auto elem{ elements };
	for (size_t i{ 0 }; i != size(); ++i)
	{
		alloc_traits_t::construct(alloc, dest++, std::move(*elem++));
	}
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

void String::reserve(size_t n)
{
	if (n > capacity())
	{
		auto newcapacity{ n };
		auto newdata{ alloc.allocate(newcapacity) };
		auto dest{ newdata };
		auto elem{ elements };
		for (size_t i{ 0 }; i != size(); ++i)
		{
			alloc_traits_t::construct(alloc, dest++, std::move(*elem++));
		}
		free();
		elements = newdata;
		first_free = dest;
		cap = elements + newcapacity;
	}
}

void String::push_back(const char& s)
{
	chk_n_alloc();
	alloc_traits_t::construct(alloc, first_free++, s);
}

void String::pop_back()
{
	if (size() > 0)
	{
		alloc_traits_t::destroy(alloc, --first_free);
	}
}

void String::resize(size_t n, const char& s = '\0')
{
	if (n > size())
	{
		for (size_t i{ size() }; i < n; ++i)
		{
			push_back(s);
		}
	}
	else if (n < size())
	{
		for (size_t i{ size() }; i > n; --i)
		{
			pop_back();
		}
	}
}

String::String(String&& s) noexcept :
	elements{ s.elements }, first_free{ s.first_free }, cap{ s.cap }
{
	s.elements = s.first_free = s.cap = nullptr;
}

String& String::operator=(String&& rhs) noexcept
{
	if (this != &rhs)
	{
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const String& s)
{
	for (auto b{s.elements}; b != s.first_free; ++b)
	{
		os << *b;
	}
	return os;
}

bool operator== (const String& lhs, const String& rhs)
{
	if (lhs.size() != rhs.size())
	{
		return false;
	}

	for (const char* p1{ lhs.elements }, * p2{ rhs.elements }; p1 != lhs.first_free; ++p1, ++p2)
	{
		if (*p1 != *p2)
		{
			return false;
		}
	}

	return true;
}

bool operator!= (const String& lhs, const String& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const String& lhs, const String& rhs)
{
	const char* p1{ lhs.elements }, * p2{ rhs.elements };

	for (; p1 != lhs.first_free && p2 != rhs.first_free; ++p1, ++p2)
	{
		if (*p1 < *p2)
		{
			return true;
		}
		if (*p1 > *p2)
		{
			return false;
		}
	}
	if (p1 == lhs.first_free && p2!=rhs.first_free)
	{
		return true;
	}

	return false;
}

bool operator<=(const String& lhs, const String& rhs)
{
	return !(lhs > rhs);
}

bool operator>(const String& lhs, const String& rhs)
{
	const char* p1{ lhs.elements }, * p2{ rhs.elements };

	for (; p1 != lhs.first_free && p2 != rhs.first_free; ++p1, ++p2)
	{
		if (*p1 > *p2)
		{
			return true;
		}
		if (*p1 < *p2)
		{
			return false;
		}
	}
	if (p1 != lhs.first_free && p2 == rhs.first_free)
	{
		return true;
	}

	return false;
}
bool operator>=(const String& lhs, const String& rhs)
{
	return !(lhs < rhs);
}

#endif // !NEW_STRING_H
