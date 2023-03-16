#include "common.hpp"
#include <vector>

#define T1 int
#define T2 int
typedef _pair<const T1, T2> T3;

void operator_details(NAMESPACE::map<T1, T2> m)
{
	std::cout << "value at 1 : " << m[1] << std::endl;
	std::cout << "value at 3 : " << m[3] << std::endl;
	std::cout << "value at 7 : " << m[7] << std::endl;
	std::cout << std::endl;
	printDetails(m);
}

int		main(void)
{
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = exec_time.tv_sec + exec_time.tv_usec;

	std::cout << "Creating Vector V1" << std::endl;
	std::vector<T3> v1;
	unsigned int v1_size = 5;
	for (unsigned int i = 0; i < v1_size; ++i)
		v1.push_back(T3(v1_size - i, (v1_size - i) * 3));

	std::cout << "Creating MAP with values from V1" << std::endl;
	NAMESPACE::map<T1, T2> m1(v1.begin(), v1.end());
	printDetails(m1);

	operator_details(m1);	

	gettimeofday(&exec_time, NULL);
	double end = exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << std::endl;
}