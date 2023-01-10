#include "common.hpp"

int main()
{
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = exec_time.tv_sec + exec_time.tv_usec;

	NAMESPACE::vector<TEST_TYPE> v1(5);
	NAMESPACE::vector<TEST_TYPE> v2;
	NAMESPACE::vector<TEST_TYPE> v3;

	for (unsigned long int i = 0; i < v1.size(); ++i)
		v1[i] = i + 1;
	printDetails(v1);

	for (unsigned long int i = 0; i < 3; ++i)
		v2.push_back(i);
	printDetails(v2);

	v3.assign(v1.begin(), v1.end());
	printDetails(v3);

	v2.assign(2, 42);
	printDetails(v2);

	v2.pop_back();
	printDetails(v2);

	v1.erase(v1.begin());
	printDetails(v1);

	v1.erase(v1.begin(), v1.begin()+2);
	printDetails(v1);
	
	v1.insert(v1.begin(), 0);
	printDetails(v1);

	v1.insert(v1.begin(), 3, 42);
	printDetails(v1);

	v2.clear();
	printDetails(v2);

	gettimeofday(&exec_time, NULL);
	double end = exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}