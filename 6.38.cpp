#include <iostream>

int odd[]{ 1,3,5,7,9 };
int even[]{ 0,2,4,6,8 };

decltype((odd)) arrRef(int i);

int main()
{
	for (auto i : arrRef(2))
	{
		std::cout << i << std::endl;
	}

	return 0;
}

decltype((odd)) arrRef(int i)
{
	return (i % 2) ? odd : even;
}
