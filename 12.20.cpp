#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "Str_Blob.h"

int main()
{
	std::ifstream ifs{ "./12.20.txt" };
	std::string line;


	while (std::getline(ifs, line))
	{
		std::string s;
		std::istringstream iss{ line };
		StrBlob strBlob;
		StrBlobPtr p{ strBlob };

		while (iss >> s)
		{
			strBlob.push_back(s);
		}
		for (auto i{ 0U }; i < strBlob.size(); ++i)
		{
			std::cout << p.deref() << ' ';
			p.incr();
		}
		std::cout << std::endl;
	}

	return 0;
}