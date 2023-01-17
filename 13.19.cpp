#include <string>
#include <iostream>

class Employee
{
public:
	Employee() :id{ serial_num++ } {};

	Employee(const std::string& s) : id{ serial_num++ }, name{ s } {};

	Employee(const Employee& origin)
	{
		id = origin.serial_num++;
		name = origin.name;
	}

	Employee& operator=(const Employee& origin)
	{
		this->id = origin.serial_num++;
		name = origin.name;
		return *this;
	}

	int id;
	std::string name;
private:
	static int serial_num;
};

int Employee::serial_num{ 0 };

int main()
{
	Employee e1{}, e2{ "John" };
	Employee e3{ e2 };
	Employee e4{};

	e4 = e1;

	std::cout << e1.id << " : " << e1.name << std::endl;
	std::cout << e2.id << " : " << e2.name << std::endl;
	std::cout << e3.id << " : " << e3.name << std::endl;
	std::cout << e4.id << " : " << e4.name << std::endl;

	return 0;
}
