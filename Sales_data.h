#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

class Sales_data {

	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::ostream& print(std::ostream&, const Sales_data&);
	friend std::istream& read(std::istream&, Sales_data&);
	friend std::ostream& operator<<(std::ostream&, const Sales_data&);
	friend std::istream& operator>>(std::istream&, Sales_data&);
	friend Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs);
	friend Sales_data operator-(const Sales_data& lhs, const Sales_data& rhs);
	friend bool operator==(const Sales_data& lhs, const Sales_data& rhs);
	friend bool operator!=(const Sales_data& lhs, const Sales_data& rhs);
public:
	Sales_data(const std::string& s, unsigned int n, double p) :bookNo(s), units_sold(n), revenue(p* n) {}

	Sales_data() :Sales_data("", 0, 0) {}
	Sales_data(const std::string& s) :Sales_data(s, 0, 0) {}
	Sales_data(std::istream& is) :Sales_data() { read(is, *this); }
	Sales_data& operator+=(const Sales_data&);
	Sales_data& operator-=(const Sales_data&);

	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;

private:
	std::string bookNo;
	unsigned int units_sold{ 0 };
	double revenue{ 0.0 };
};

Sales_data accum, trans, * salesptr;

double Sales_data::avg_price() const
{
	if (units_sold)
	{
		return revenue / units_sold;
	}
	else
	{
		return 0;
	}
}

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}
std::ostream& print(std::ostream& os, const Sales_data& item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}
std::istream& read(std::istream& is, Sales_data& item)
{
	double price{ 0.0 };
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Sales_data& item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

std::istream& operator>>(std::istream& is, Sales_data& item)
{
	double price{ 0.0 };
	is >> item.bookNo >> item.units_sold >> price;
	if (is)
	{
		item.revenue = price * item.units_sold;
	}
	else
	{
		item = Sales_data();
	}

	return is;
}

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data sum{ lhs };
	sum += rhs;
	return sum;
}

Sales_data& Sales_data::operator+=(const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_data operator-(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data sub{ lhs };
	sub -= rhs;
	return sub;
}

Sales_data& Sales_data::operator-=(const Sales_data& rhs)
{
	units_sold -= rhs.units_sold;
	revenue -= rhs.revenue;
	return *this;
}

bool operator==(const Sales_data& lhs, const Sales_data& rhs)
{
	return lhs.isbn() == rhs.isbn()
		&& lhs.units_sold == rhs.units_sold
		&& lhs.revenue == rhs.revenue;
}
bool operator!=(const Sales_data& lhs, const Sales_data& rhs)
{
	return !(lhs == rhs);
}

#endif
