#include "common.hpp"

template <class T_STACK>
void	cmp(const T_STACK &x, const T_STACK &y)
{
	std::cout << "EQUALITY : " ;
	if (x == y)
		std::cout << "equal" << std::endl;
	else if (x != y)
		std::cout << "not equal" << std::endl;
	std::cout << "GT/GE    : ";
	if (x > y)
		std::cout << "greater than ";
	if (x >= y)
		std::cout << "& equal to"  << std::endl;
	std::cout << "LT/LE    : ";
	if (x < y)
		std::cout << "less than ";
	if (x <= y)
		std::cout << "& equal to"  << std::endl;
}

int main()
{
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = exec_time.tv_sec + exec_time.tv_usec;


	NAMESPACE::stack<TEST_TYPE> s1;
	NAMESPACE::stack<TEST_TYPE> s2;

	std::cout << "\tSTACK\t\n" << std::endl;

	std::cout << "\nFILLING STACK 1" << std::endl;
	s1.push(5);
	s1.push(10);
	s1.push(15);
	s1.push(20);
	std::cout << "\nCOMPARING STACK 1 & STACK 2" << std::endl;
	cmp(s1, s2);
	std::cout << "###############################################" << std::endl;

	std::cout << "\nCREATING ANOTHER STACK 3 & COMPARNG" << std::endl;
	NAMESPACE::stack<TEST_TYPE> s3(s1);
	s3.push(25);
	printDetails(s3);
	cmp(s1, s3);
	std::cout << "###############################################" << std::endl;

	std::cout << "\nPOP STACK 2 & COMPARNG" << std::endl;
	s3.pop();
	printDetails(s3);
	cmp(s1, s3);
	std::cout << "###############################################" << std::endl;

	gettimeofday(&exec_time, NULL);
	double end = exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}