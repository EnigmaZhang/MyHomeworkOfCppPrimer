#include <iostream>
#include <vector>

template<typename T>
void printVector(const std::vector<T>& v);

int main()
{
	std::vector<int> v{ 1,2,3 };
	printVector(v);

	return 0;
}

template<typename T>
void printVector(const std::vector<T>& v)
{
#ifndef NDEBUG
	std::cout << "The size of vector is: " << v.size() << std::endl;
#endif // !NDEBUG


	if (!v.empty())
	{
		std::cout << v[0] << std::endl;
		printVector(std::vector(v.cbegin() + 1, v.cend()));
	}

}
