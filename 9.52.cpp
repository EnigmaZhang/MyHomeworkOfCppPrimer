#include <iostream>
#include <stack>
#include <string>

int main()
{
	std::stack<char> processor;
	std::stack<char> tmp;
	std::string s{ "(1 + 2) * 4 - (9 ^(114514 * 2))" };
	std::string result;
	// # represents result
	for (auto c : s)
	{
		processor.push(c);
		if (processor.top() == ')')
		{
			processor.pop();
			while (processor.top() != '(')
			{
				tmp.push(processor.top());
				processor.pop();
			}
			processor.pop();
			while (!tmp.empty())
			{
				tmp.pop();
			}
			processor.push('#');
		}
	}
	while (!processor.empty())
	{
		result += processor.top();
		processor.pop();
	}
	std::cout << result << std::endl;

	return 0;
}
