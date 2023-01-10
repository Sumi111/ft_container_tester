#ifndef COMMON_HPP
#define COMMON_HPP

#include "../../../ft_container/includes/vector.hpp"
#include <vector>

#include <sys/time.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>

#define TEST_TYPE int

void printDetails(NAMESPACE::vector<TEST_TYPE> s)
{
	std::cout << "size     : " << s.size() << std::endl;
	std::cout << "empty    : " << s.empty() << std::endl;

	if (!s.empty())
	{
		std::cout << "Vector's content is : \t";
		while(s.size() != 0)
		{
			std::cout << s.back() << "\t";
			s.pop_back();
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

#endif