#include "common.hpp"

int main()
{
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = exec_time.tv_sec + exec_time.tv_usec;

	NAMESPACE::vector<TEST_TYPE> v1;
	for(int i = 0; i < 5; i++)
		v1.push_back(i+1);
	printDetails(v1);

	NAMESPACE::vector<TEST_TYPE> v2(v1.begin(), v1.end());
	printDetails(v2);

	NAMESPACE::vector<TEST_TYPE> v3(5);
	NAMESPACE::vector<TEST_TYPE>::reverse_iterator rit = v3.rbegin();
	int i=0;

  	for (; rit!= v3.rend(); ++rit)
    	*rit = ++i;

	printDetails(v3);

	gettimeofday(&exec_time, NULL);
	double end = exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}