#include <iostream>

class TernaryFunctionClass
{
public:
	template <typename T>
	T operator()(bool e, T first, T second)
	{
		return e ? first : second;
	}


};

int main()
{
	TernaryFunctionClass t = TernaryFunctionClass();
	std::cout << t((4.00 > 5.00), 1, 2) << std::endl;

	return 0;
}