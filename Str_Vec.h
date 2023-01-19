#ifndef STR_VEC_H
#define STR_VEC_H

#include <string>
#include <memory>
#include <utility>
#include <algorithm>

class StrVec
{
public:
	StrVec() :
		elements{ nullptr }, first_free{ nullptr }, cap{ nullptr } {}
	StrVec(std::initializer_list<std::string>);
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);
	~StrVec();
	StrVec(StrVec&& s) noexcept;
	StrVec& operator=(StrVec&& rhs) noexcept;
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	void reserve(size_t);
	void resize(size_t n, const std::string& s);
	void push_back(const std::string&);
	void pop_back();
	std::string* begin() const { return elements; }
	std::string* end() const { return first_free; }
private:
	std::allocator<std::string> alloc;
	using alloc_traits_t = std::allocator_traits<decltype(alloc)>;

	void chk_n_alloc()
	{
		if (size() == capacity())
		{
			reallocate();
		}
	}
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
	void free();
	void reallocate();
	std::string* elements;
	std::string* first_free;
	std::string* cap;
};

StrVec::StrVec(const StrVec& s)
{
	auto newdata{ alloc_n_copy(s.begin(), s.end()) };
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::StrVec(std::initializer_list<std::string> ls) :
	elements{ nullptr }, first_free{ nullptr }, cap{ nullptr }
{
	auto newdata{ alloc_n_copy(ls.begin(), ls.end()) };
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec& StrVec::operator=(const StrVec& rhs)
{
	auto data{ alloc_n_copy(rhs.begin(), rhs.end()) };
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

StrVec::~StrVec()
{
	free();
}

std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string* b, const std::string* e)
{
	auto data{ alloc.allocate(e - b) };
	return { data, std::uninitialized_copy(b,e,data) };
}

void StrVec::free()
{
	if (elements)
	{
		std::for_each(elements, first_free, 
			[this](std::string p) { alloc_traits_t::destroy(this->alloc, &p); });
		alloc.deallocate(elements, cap - elements);
	}
}

void StrVec::reallocate()
{
	auto newcapacity{ size() ? 2 * size() : 1 };
	auto first{ alloc.allocate(newcapacity) };

	auto last{ std::uninitialized_copy(std::make_move_iterator(begin()), std::make_move_iterator(end()), first) };
	free();
	elements = first;
	first_free = last;
	cap = elements + newcapacity;
}

void StrVec::reserve(size_t n)
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

void StrVec::push_back(const std::string& s)
{
	chk_n_alloc();
	alloc_traits_t::construct(alloc, first_free++, s);
}

void StrVec::pop_back()
{
	if (size() > 0)
	{
		alloc_traits_t::destroy(alloc, --first_free);
	}
}

void StrVec::resize(size_t n, const std::string& s = "")
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

StrVec::StrVec(StrVec&& s) noexcept:
	elements{s.elements}, first_free{s.first_free},cap{s.cap}
{
	s.elements = s.first_free = s.cap = nullptr;
}

StrVec& StrVec::operator=(StrVec&& rhs) noexcept
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

#endif // !STR_VEC_H
