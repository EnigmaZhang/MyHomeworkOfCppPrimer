#ifndef STR_BLOB_H
#define STR_BLOB_H

#include <vector>
#include <string>
#include <memory>
#include <stdexcept>

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob
{
public:
	friend bool operator==(const StrBlob& lhs, const StrBlob& rhs);
	friend bool operator!=(const StrBlob& lhs, const StrBlob& rhs);

	using size_type = std::vector<std::string>::size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	std::string& operator[](size_t n) { return data.get()->at(n); }
	const std::string& operator[](size_t n) const { return data.get()->at(n); }

	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const std::string& t) { data->push_back(t); }
	void push_back(std::string&& t) { data->push_back(t); };
	void pop_back();
	std::string& front() const;
	std::string& back() const;

	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;
	StrBlobPtr begin();
	StrBlobPtr end();
	ConstStrBlobPtr cbegin();
	ConstStrBlobPtr cend();
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string& msg) const;
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {};

StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}

void StrBlob::check(size_type i, const std::string& msg) const
{
	if (i >= data->size())
	{
		throw std::out_of_range(msg);
	}
}

std::string& StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();
}

std::string& StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

bool operator==(const StrBlob& lhs, const StrBlob& rhs)
{
	return *lhs.data == *rhs.data;
}

bool operator!=(const StrBlob& lhs, const StrBlob& rhs)
{
	return !(lhs == rhs);
}

class StrBlobPtr
{
public:
	friend bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
	friend bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
	friend StrBlobPtr operator+(std::ptrdiff_t n, StrBlobPtr& rhs);

	StrBlobPtr() :curr(0) {}
	StrBlobPtr(StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz) {}
	std::string& operator[](size_t n) { return check(n, "get a subscript").get()->at(n); }
	const std::string& operator[](size_t n) const { return check(n, "get a subscript").get()->at(n); }
	StrBlobPtr& operator++();
	StrBlobPtr& operator--();
	StrBlobPtr& operator++(int n);
	StrBlobPtr& operator--(int n);
	StrBlobPtr operator+(std::ptrdiff_t n);
	StrBlobPtr& operator+=(std::ptrdiff_t n);
	StrBlobPtr operator-(std::ptrdiff_t n);
	StrBlobPtr& operator-=(std::ptrdiff_t n);

	std::string& deref() const;
	StrBlobPtr& incr();
private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); };
StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); };

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string& msg) const
{
	auto ret{ wptr.lock() };
	if (!ret)
	{
		throw std::runtime_error("unbound StrBlobPtr");
	}
	if (i >= ret->size())
	{
		throw std::out_of_range(msg);
	}
	return ret;
}

std::string& StrBlobPtr::deref() const
{
	auto p{ check(curr, "dereference past end") };
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobStr");
	++curr;
	return *this;
}

bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	return lhs.curr == rhs.curr && lhs.wptr.lock() == rhs.wptr.lock();
}
bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	return !(lhs == rhs);
}


StrBlobPtr& StrBlobPtr::operator++()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;

}

StrBlobPtr& StrBlobPtr::operator--()
{
	--curr;
	check(curr, "decrement past begin of StrBlobPtr");
	return *this;
}

StrBlobPtr& StrBlobPtr::operator++(int)
{
	auto ret{ *this };
	++* this;
	return ret;

}

StrBlobPtr& StrBlobPtr::operator--(int)
{
	auto ret{ *this };
	--* this;
	return ret;
}

StrBlobPtr StrBlobPtr::operator+(std::ptrdiff_t n)
{
	auto ret{ *this };
	ret += n;
	return ret;
}

StrBlobPtr& StrBlobPtr::operator+=(std::ptrdiff_t n)
{
	curr = curr + n;
	check(curr, "increment past end of StrBlobPtr");
	return *this;
}


StrBlobPtr StrBlobPtr::operator-(std::ptrdiff_t n)
{
	auto ret{ *this };
	ret -= n;
	return ret;
}

StrBlobPtr& StrBlobPtr::operator-=(std::ptrdiff_t n)
{
	curr -= n;
	check(curr, "decrement past begin of StrBlobPtr");
	return *this;
}

StrBlobPtr operator+(std::ptrdiff_t n, StrBlobPtr& rhs)
{
	return rhs + n;
}


class ConstStrBlobPtr
{
public:
	friend bool operator==(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs);
	friend bool operator!=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs);

	ConstStrBlobPtr() :curr(0) {}
	ConstStrBlobPtr(const StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz) {}
	std::string& operator[](size_t n) { return check(n, "get a subscript").get()->at(n); }
	const std::string& operator[](size_t n) const { return check(n, "get a subscript").get()->at(n); }
	std::string& deref() const;
	ConstStrBlobPtr& incr();
private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};

ConstStrBlobPtr StrBlob::cbegin() { return ConstStrBlobPtr(*this); };
ConstStrBlobPtr StrBlob::cend() { return ConstStrBlobPtr(*this, data->size()); };

std::shared_ptr<std::vector<std::string>> ConstStrBlobPtr::check(std::size_t i, const std::string& msg) const
{
	auto ret{ wptr.lock() };
	if (!ret)
	{
		throw std::runtime_error("unbound StrBlobPtr");
	}
	if (i >= ret->size())
	{
		throw std::out_of_range(msg);
	}
	return ret;
}

std::string& ConstStrBlobPtr::deref() const
{
	auto p{ check(curr, "dereference past end") };
	return (*p)[curr];
}

ConstStrBlobPtr& ConstStrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobStr");
	++curr;
	return *this;
}

bool operator==(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
	return lhs.curr == rhs.curr && lhs.wptr.lock() == rhs.wptr.lock();
}

bool operator!=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
	return !(lhs == rhs);
}

#endif // !STR_BLOB_H
