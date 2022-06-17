#include <iostream>
#include <memory>
#include <vector>
#include <string>

#include "Str_Blob.h"

int main()
{
	const StrBlob strBlob{ "a", "b", "c" };
	ConstStrBlobPtr p{ strBlob };

	for (auto i{ 0U }; i < strBlob.size(); ++i)
	{
		std::cout << p.deref() << ' ';
		p.incr();
	}
	std::cout << std::endl;

	return 0;
}