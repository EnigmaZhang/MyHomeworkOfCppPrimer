#include <iostream>

class FixedPoint
{
public:
	FixedPoint(const int integer, const int decimal)
		: integer(integer), decimal(decimal) {};

	friend std::ostream& operator<<(std::ostream&, const FixedPoint&);

	int getInteger() { return integer; };

	int getDecimal() { return decimal; };

private:
	int integer;
	int decimal;
};

int main()
{
	std::cout << FixedPoint(9, 55) << std::endl;
	
	return 0;
}

std::ostream& operator<<(std::ostream& out, const FixedPoint& fixedPoint)
{
	out << fixedPoint.integer << "." << fixedPoint.decimal;
	return out;
}
