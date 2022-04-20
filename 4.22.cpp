#include <iostream>
#include <vector>
#include <string>

int main()
{	
	std::vector<int> grades{ 40, 61, 80, 99 };

	for (auto grade : grades)
	{
		std::cout << grade << " is " <<
			(grade < 60 ? "fail" : grade < 75 ? "low pass" : grade < 90 ? "pass" : "high pass") << std::endl;
		std::string s;
		if (grade < 60)
		{
			s = "fail";
		}
		else if (grade < 75)
		{
			s = "low pass";
		}
		else if (grade < 90)
		{
			s = "pass";
		}
		else
		{
			s = "high pass";
		}
		std::cout << grade << " is " << s << std::endl;
	}

	return 0;
}
