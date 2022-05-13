#include <iostream>
#include "Screen.h"

int main()
{
	Window_mgr win = Window_mgr();
	Screen s{ Screen(4, 3, 'X') };
	win.addScreen(s);
	win.clear(0);

	win.getScreen(0).display(std::cout);
	std::cout << std::endl;

	return 0;
}
