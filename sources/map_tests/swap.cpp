#include "common.hpp"
#include <vector>

#define T1 int
#define T2 int
typedef _pair<const T1, T2> T3;

int		main(void)
{
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = exec_time.tv_sec + exec_time.tv_usec;

	std::vector<T3> v1;
	unsigned int v1_size = 5;
	for (unsigned int i = 0; i < v1_size; ++i)
		v1.push_back(T3(v1_size - i, i * 5));

	std::cout << "Creating MAP with values from V1" << std::endl;
	NAMESPACE::map<T1, T2> m1(v1.begin(), v1.end());
	printDetails(m1);

	std::vector<T3> v2;
	unsigned int v2_size = 5;
	for (unsigned int i = 0; i < v2_size; ++i)
		v2.push_back(T3(v2_size - i, i * 3));
	std::cout << "Creating MAP with values from V2" << std::endl;
	NAMESPACE::map<T1, T2> m2(v2.begin(), v2.end());
	printDetails(m2);

	m1.swap(m2);
	std::cout << "M1 after swap" << std::endl;
	printDetails(m1);
	std::cout << "M2 after swap" << std::endl;
	printDetails(m2);

	std::cout << "Clearing M1" << std::endl;
	m1.clear();
	printDetails(m1);

	gettimeofday(&exec_time, NULL);
	double end = exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << std::endl;
}