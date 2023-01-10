#ifndef COMMON_HPP
#define COMMON_HPP

#include "../../../ft_container/includes/stack.hpp"
#include <stack>

#include <sys/time.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>

#define TEST_TYPE int

void printDetails(NAMESPACE::stack<TEST_TYPE> s)
{
	std::cout << "size : " << s.size() << std::endl;
	std::cout << "empty: " << s.empty() << std::endl;

	if (!s.empty())
	{
		std::cout << "Stack's content is : \t";
		while(s.size() != 0)
		{
			std::cout << s.top() << "\t";
			s.pop();
		}
	}
	std::cout << std::endl;
}

#endif