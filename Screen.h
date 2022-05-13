#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <vector>

class Screen;

class Window_mgr
{
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	const Screen& getScreen(ScreenIndex i) const { return screens.at(i); }
	Window_mgr& addScreen(Screen& screen) { screens.push_back(screen); return *this; }
	void clear(ScreenIndex);
private:
	std::vector<Screen> screens;
};

class Screen
{
public:
	using pos = std::string::size_type;
	Screen() = default;
	Screen(pos ht, pos wd, char c = ' ') :height(ht), width(wd), contents(ht* wd, c) {};
	char get() const { return contents[cursor]; }
	inline char get(pos r, pos c) const;
	Screen& move(pos r, pos c);
	Screen& set(char);
	Screen& set(pos, pos, char);
	Screen& display(std::ostream& os) { do_display(os); return *this; }
	const Screen& display(std::ostream& os) const { do_display(os); return*this; }
	friend void Window_mgr::clear(ScreenIndex);
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

inline Screen& Screen::move(pos r, pos c)
{
	pos row{ r * width };
	cursor = row + c;
	return *this;
}

inline Screen& Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

inline Screen& Screen::set(pos r, pos col, char ch)
{
	contents[r * width + col] = ch;
	return *this;
}

void Window_mgr::clear(ScreenIndex i)
{
	Screen& s = screens[i];
	s.contents = std::string(s.height * s.width, ' ');
}

#endif