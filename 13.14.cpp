#include <string>
#include <iostream>

class Numbered
{
public:
	Numbered()
	{
		mysn = serial_num++;
	}

	int mysn;
private:
	static int serial_num;
};
int Numbered::serial_num = 0;

void f(Numbered s);

void f(Numbered s)
{
	std::cout << s.mysn << std::endl;
}

int main()
{
	Numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);

	return 0;
}
