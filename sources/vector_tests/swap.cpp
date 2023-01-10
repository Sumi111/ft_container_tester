#include "common.hpp"

int main()
{
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = exec_time.tv_sec + exec_time.tv_usec;


	NAMESPACE::vector<TEST_TYPE> v1;
	NAMESPACE::vector<TEST_TYPE> v2;

	std::cout << "BEFORE SWAPPING" << std::endl;
	for(int i = 0; i < 5; i++)
		v1.push_back(i*5);

	for(int i = 0; i < 10; i++)
		v2.push_back(i*2);
	std::cout << "Vector 1" << std::endl;
	printDetails(v1);
	std::cout << "Vector 2" << std::endl;
	printDetails(v2);

	std::cout << "AFTER SWAPPING" << std::endl;
	v2.swap(v1);
	std::cout << "Vector 1" << std::endl;
	printDetails(v1);
	std::cout << "Vector 2" << std::endl;
	printDetails(v2);

	gettimeofday(&exec_time, NULL);
	double end = exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}