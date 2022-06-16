#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <iomanip>

class Year
{
public:
	Year(const std::string& date);
	unsigned int year;
	unsigned int month;
	unsigned int day;
private:
	const static std::string delimiter;
	const static std::string nums;
	const static std::array<const std::string, 12> months;
};
const std::string Year::delimiter{ " /,." };
const std::string Year::nums{ "0123456789" };
const std::array<const std::string, 12> Year::months{ 
	"Jan","Feb", "Mar", "Apr", "May","Jun","Jul","Aug","Sep","Oct", "Nov", "Dec" };

Year::Year(const std::string& date)
{
	std::vector<std::string> v;
	std::string month_s, day_s, year_s;
	std::string::size_type pos1{ 0 };
	std::string::size_type pos2{ 0 };
	while ((pos2 = date.find_first_of(delimiter, pos2)) != std::string::npos)
	{
		if (pos2 != pos1)
		{
			v.push_back(date.substr(pos1, pos2));
		}
		++pos2;
		pos1 = pos2;
	}
	if (pos1 != date.length())
	{
		v.push_back(date.substr(pos1));
	}
	if (v.size() != 3)
	{
		throw std::invalid_argument("argument date don't have three date members");
	}
	month_s = v.at(0);
	day_s = v.at(1);
	year_s = v.at(2);
	day = std::stoi(day_s);
	year = std::stoi(year_s);
	if (month_s.find_first_not_of(nums) == std::string::npos)
	{
		month = std::stoi(month_s);
	}
	else
	{
		for (std::array<std::string, 12>::size_type i{ 0 }; i < 12; ++i)
		{
			if (month_s.find(months.at(i)) != std::string::npos)
			{
				month = static_cast<unsigned int>(i + 1);
				break;
			}
		}
	}
}

void print_year_as_yyyyMMdd(const Year& year);

int main()
{
	Year a{ "January 1, 1900" }, b{ "1/1/1900" }, c{ "Jan 1, 1900" }, d{ "1.1.1900" };
	print_year_as_yyyyMMdd(a);
	print_year_as_yyyyMMdd(b);
	print_year_as_yyyyMMdd(c);
	print_year_as_yyyyMMdd(d);

	return 0;
}



void print_year_as_yyyyMMdd(const Year& year)
{
	std::cout << std::setfill('0') << std::setw(4) << year.year << std::setw(2) << year.month << std::setw(2) << year.day << std::endl;
}
