#include <string>
#include <iostream>
#include <vector>
#include <memory>

class StrBlob
{
public:
	using size_type = std::vector<std::string>::size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);

	StrBlob(const StrBlob& origin)
	{
		data = std::make_shared<std::vector<std::string>>(*origin.data);
	}

	StrBlob& operator=(const StrBlob& origin)
	{
		data = std::make_shared<std::vector<std::string>>(*origin.data);
		return *this;
	}

	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const std::string& t) { data->push_back(t); }

private:
	std::shared_ptr<std::vector<std::string>> data;
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {};

StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {};

int main()
{
	StrBlob s{ "aaa", "bbb" };
	StrBlob s2{ s };
	StrBlob s3;

	s2.push_back("ccc");
	s2.push_back("ddd");
	s3 = s;
	s.push_back("ok");

	std::cout << s.size() << std::endl;
	std::cout << s2.size() << std::endl;
	std::cout << s3.size() << std::endl;

	return 0;
}