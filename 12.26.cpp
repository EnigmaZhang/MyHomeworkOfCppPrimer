#include <iostream>
#include <string>
#include <memory>

int main()
{
	size_t n{ 1024 };
	std::allocator<std::string> alloc;

	using traits_t = std::allocator_traits<decltype(alloc)>;

	auto const p{ alloc.allocate(n) };
	std::string* q{ p };
	std::string s;

	while (std::cin >> s && q != p + n)
	{
		traits_t::construct(alloc, q, s);
	}
	while (q != p)
	{
		traits_t::destroy(alloc, --q);
	}
	traits_t::deallocate(alloc, p, n);

	return 0;
}