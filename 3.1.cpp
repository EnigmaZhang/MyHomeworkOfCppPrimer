#include <iostream>

using std::cin, std::cout, std::endl;

int main()
{
	int a, b;

	cout << "Please input two integers: " << endl;

	cin >> a >> b;

	int smaller{ a < b ? a : b };
	int larger{ a > b ? a : b };

	int n{ smaller + 1 };

	cout << "Numbers between "
		<< smaller << " and " << larger << " are: " << endl;
	while (n < larger)
	{
		cout << n << "\t";
		n++;
	}

	cout << endl;

	return 0;
}