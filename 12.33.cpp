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
	auto qr{ tq.query("Hello") };
	std::cout << qr.get_file().use_count() << std::endl;
}