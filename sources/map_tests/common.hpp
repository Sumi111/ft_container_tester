#ifndef COMMON_HPP
#define COMMON_HPP

#include "../../../includes/map.hpp"
#include <map>

#include <sys/time.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>

// #define TEST_TYPE NAMESPACE::pair<int, int>
#define _pair NAMESPACE::pair


template <typename T>
std::string	printPair(const T &iterator)
{
	std::cout << "key: " << iterator->first << " | value: " << iterator->second;
	return ("");
}

template <typename T_MAP>
void printDetails(T_MAP m)
{
	std::cout << "size     : " << m.size() << std::endl;
	std::cout << "empty    : " << m.empty() << std::endl;

	typename T_MAP::const_iterator it = m.begin(), ite = m.end();
	std::cout << "content:" << std::endl;
	for (; it != ite; ++it)
		std::cout << "- " << printPair(it) << std::endl;
	

	std::cout << std::endl;
}

#endif
