#include "common.hpp"

int main()
{
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = exec_time.tv_sec + exec_time.tv_usec;

	std::cout << "Capacity" << std::endl;

	NAMESPACE::vector<TEST_TYPE> v1(3); 
	NAMESPACE::vector<TEST_TYPE> v2;

	printDetails(v1);
	std::cout << "Max_size : " << v1.max_size() << std::endl;
	std::cout << "Capacity : " << v1.capacity() << std::endl;


	std::cout << "\nPushing elements" << std::endl;
	v1.push_back(44);
	v1.push_back(45);
	v1.push_back(46);
	v1.push_back(47);
	printDetails(v1);

	v1.resize(5);
	printDetails(v1);

	v1.resize(10, 66);
	printDetails(v1);

	v2.reserve(5);
	std::cout << "Capacity : " << v2.capacity() << std::endl;
	printDetails(v2);
	
	gettimeofday(&exec_time, NULL);
	double end = exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
}