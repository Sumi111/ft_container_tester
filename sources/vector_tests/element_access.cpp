#include "common.hpp"

int main()
{
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = exec_time.tv_sec + exec_time.tv_usec;

	std::cout << "Element Access" << std::endl;

	NAMESPACE::vector<TEST_TYPE> v1; 

	for(int i = 0; i < 5; i++)
		v1.push_back(i);
	printDetails(v1);

	std::cout << "Element within range : at 3" << std::endl;
	std::cout << v1[3] << " and " << v1.at(3) << std::endl;

	std::cout << "Element outside range : at 30" << std::endl;
	try
	{
		v1.at(30);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
	}
	std::cout << " and " << v1[30] << std::endl;

	NAMESPACE::vector<TEST_TYPE> v2(v1);
	std::cout << "front : " << v2.front() << std::endl;
	std::cout << "back  : " << v2.back() << std::endl;

	gettimeofday(&exec_time, NULL);
	double end = exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << std::endl;
}