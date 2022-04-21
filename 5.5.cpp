#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::vector<std::string> scores = { "F","D","C","B","A","A++" };

	std::string letterGrade;
	int grade;

	std::cin >> grade;

	if (grade < 60)
	{
		letterGrade = scores[0];
	}
	else
	{
		letterGrade = scores[(grade - 50) / 10];
		if (grade != 100)
		{
			if (grade % 10 > 7)
			{
				letterGrade += '+';
			}
			else if (grade % 10 < 3)
			{
				letterGrade += '-';
			}
		}
	}

	std::cout << letterGrade << std::endl;

	return 0;
}
