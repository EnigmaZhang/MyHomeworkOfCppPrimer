#include <string>
#include <iostream>

#include "Str_Blob.h"

class StrBlobPtrPtr
{
public:
	StrBlobPtrPtr() = default;
	StrBlobPtrPtr(StrBlobPtr* p) :p{ p } {  }

	StrBlobPtr& operator*() { return *p; }
	StrBlobPtr* operator->() { return &(this->operator*()); }

private:
	StrBlobPtr* p;
};

int main()
{

	return 0;
}