#include <iostream>

class Screen
{
public:
	using pos = std::string::size_type;
	Screen() = default;
	Screen(pos ht, pos wd, char c = ' ') :height(ht), width(wd), contents(ht* wd, c) {};
	char get() const { return contents[cursor]; }
	inline char get(pos r, pos c) const;
	Screen move(pos r, pos c);
	Screen set(char);
	Screen set(pos, pos, char);
	Screen display(std::ostream& os) { do_display(os); return *this; }
	const Screen& display(std::ostream& os) const { do_display(os); return*this; }
private:
	pos cursor{ 0U };
	pos height{ 0U }, width{ 0U };
	std::string contents;

	void do_display(std::ostream& os) const { os << contents; }
};

char Screen::get(pos r, pos c) const
{
	pos row{ r * width };
	return contents[row + c];
}

inline Screen Screen::move(pos r, pos c)
{
	pos row{ r * width };
	cursor = row + c;
	return *this;
}

inline Screen Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

inline Screen Screen::set(pos r, pos col, char ch)
{
	contents[r * width + col] = ch;
	return *this;
}

int main()
{
	Screen myScreen(5, 5, 'X');
	myScreen.move(4, 0).set('#').display(std::cout);
	std::cout << std::endl;
	myScreen.display(std::cout);
	std::cout << std::endl;

	return 0;
}
