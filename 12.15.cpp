#include <iostream>

#include <vector>
#include <memory>

struct destination
{
	bool is_used;
};
struct connection
{
	destination* d;
};
connection connect(destination* d);
void disconnection(connection c);
void end_connection(connection* p);

void f(destination& d)
{
	connection c{ connect(&d) };
	std::cout << d.is_used << std::endl;
	std::shared_ptr<connection> p{ &c,[](connection* p) { disconnection(*p); } };
}

int main()
{
	destination d{ false };
	f(d);
	std::cout << d.is_used << std::endl;

	return 0;
}

connection connect(destination* d)
{
	d->is_used = true;
	return connection
	{
		d,
	};
}
void disconnection(connection c)
{
	c.d->is_used = false;
}