#ifndef STR_BLOB_H
#define STR_BLOB_H

#include <vector>
#include <string>
#include <memory>
#include <stdexcept>

class StrBlobPtr;

class StrBlob
{
public:
	using size_type = std::vector<std::string>::size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void pop_back();
	std::string& front() const;
	std::string& back() const;

	friend class StrBlobPtr;
	StrBlobPtr begin() { return StrBlobPtr(*this); };
	StrBlobPtr end() { return StrBlobPtr(*this, data->size()); };

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

class StrBlobPtr
{
public:
	StrBlobPtr() :curr(0) {}
	StrBlobPtr(StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz) {}
	std::string& deref() const;
	StrBlobPtr& incr();
private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};

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

#endif // !STR_BLOB_H
