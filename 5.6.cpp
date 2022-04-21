#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::vector<std::string> scores = { "F","D","C","B","A","A++" };

	std::string letterGrade;
	int grade;

	std::cin >> grade;

	letterGrade = grade < 60 ? scores[0] : scores[(grade - 50) / 10] + (grade == 100 ? "" : grade % 10 > 7 ? "+" : grade % 10 < 3 ? "-" : "");

	std::cout << letterGrade << std::endl;

	return 0;
}
