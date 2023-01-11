#include "common.hpp"

/* Test includes:
	* constructors
	* empty()
	* size();
	* push();
*/

int main()
{
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = exec_time.tv_sec + exec_time.tv_usec;

	NAMESPACE::stack<TEST_TYPE> s1;
	NAMESPACE::stack<TEST_TYPE> s2;

	std::cout << "\tSTACK\t\n" << std::endl;

	std::cout << "\nEMPTY STACKS" << std::endl;
	std::cout << "\nSTACK 1" << std::endl;
	printDetails(s1);
	std::cout << "\nSTACK 2" << std::endl;
	printDetails(s2);
	std::cout << "###############################################" << std::endl;
	
	std::cout << "\nFILLING STACK 1" << std::endl;
	s1.push(5);
	s1.push(10);
	s1.push(15);
	s1.push(20);
	std::cout << "\nSTACK 1" << std::endl;
	printDetails(s1);
	std::cout << "###############################################" << std::endl;

	std::cout << "\nCOPYING STACK 1 IN STACK 2" << std::endl;
	s2 = s1;
	std::cout << "\nSTACK 1" << std::endl;
	printDetails(s1);
	std::cout << "\nSTACK 2" << std::endl;
	printDetails(s2);
	std::cout << "###############################################" << std::endl;

	std::cout << "\nPOP STACK 1" << std::endl;
	while (!s1.empty())
		s1.pop();
	std::cout << "\nSTACK 1" << std::endl;
	printDetails(s1);
	std::cout << "\nSTACK 2" << std::endl;
	printDetails(s2);
	std::cout << "###############################################" << std::endl;

	gettimeofday(&exec_time, NULL);
	double end = exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << std::endl;
	return (0);
}