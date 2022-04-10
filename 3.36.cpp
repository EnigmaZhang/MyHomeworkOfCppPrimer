#include <iostream>
#include <vector>

template <typename T> 
bool compareArray(T* aBegin, T* aEnd, T* bBegin, T* bEnd);

template <typename T>
bool compareVector(const std::vector<T> v1, const std::vector<T> v2);

int main()
{
	int a[10]{ 1,2,3 };
	int b[10]{ 1,2,3,4 };

	std::cout << compareArray(std::begin(a), std::end(a), std::begin(b), std::end(b)) << std::endl;

	b[3] = 0;
	std::cout << compareArray(std::begin(a), std::end(a), std::begin(b), std::end(b)) << std::endl;

	b[3] = 4;
	std::vector<int> v1{ a, a + 10 };
	std::vector<int> v2{ b, b + 10 };

	std::cout << compareVector(v1, v2) << std::endl;

	v2[3] = 0;
	std::cout << compareVector(v1, v2) << std::endl;

	return 0;
}

template <typename T>
bool compareArray(T* aBegin, T* aEnd, T* bBegin, T* bEnd)
{
	T * aP{ aBegin }, * bP{ bBegin };
	for (; aP < aEnd && bP < bEnd; aP++, bP++)
	{
		if (*aP != *bP)
		{
			return false;
		}
	}
	if (aP != aEnd || bP != bEnd)
	{
		return false;
	}
	else
	{
		return true;
	}
	
}

template <typename T>
bool compareVector(const std::vector<T> v1, const std::vector<T> v2)
{
	if (v1.size() != v2.size())
	{
		return false;
	}

	for (decltype(v1.size()) i{ 0 }; i < v1.size(); i++)
	{
		if (v1[i] != v2[i])
		{
			return false;
		}
	}
	return true;
}