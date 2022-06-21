#include <iostream>
#include <fstream>

#include "Text_Query.h"

void runQueries(std::ifstream& infile);

int main()
{
	std::ifstream ifs("./12.30.txt");
	runQueries(ifs);

	return 0;
}

void runQueries(std::ifstream& infile)
{
	TextQuery tq(infile);
	while (true)
	{
		std::cout << "enter word to look for, or q to quit: ";
		std::string s;
		if (!(std::cin >> s) || s == "q")
		{
			break;
		}
		print(std::cout, tq.query(s)) << std::endl;
	}
}