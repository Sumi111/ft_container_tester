#include "common.hpp"

int main()
{
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = exec_time.tv_sec + exec_time.tv_usec;

	std::cout << "VECTOR" << std::endl;

	NAMESPACE::vector<TEST_TYPE> v1(5); //default
	NAMESPACE::vector<TEST_TYPE> v2;

	printDetails(v1);
	printDetails(v2);

	v1.push_back(4);
	v1.push_back(2);
	v1.push_back(1);
	v1.push_back(-5);
	printDetails(v1);

	NAMESPACE::vector<TEST_TYPE> v3(5, 42);	//fill
	printDetails(v3);

	
	NAMESPACE::vector<TEST_TYPE> v4(v1.begin(), v1.end());	//range
	printDetails(v4);

	gettimeofday(&exec_time, NULL);
	double end = exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}