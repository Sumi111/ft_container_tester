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

	std::cout << "Creating Vector V1" << std::endl;
	std::vector<T3> v1;
	unsigned int v1_size = 5;
	for (unsigned int i = 0; i < v1_size; ++i)
		v1.push_back(T3(v1_size - i, i));

	std::cout << "Creating MAP with values from V1" << std::endl;
	NAMESPACE::map<T1, T2> m1(v1.begin(), v1.end());
	printDetails(m1);

	std::cout << "Copying M1 into M2" << std::endl;
	NAMESPACE::map<T1, T2> m2(m1);
	printDetails(m2);

	std::cout << "Changing second value in M2" << std::endl;
	NAMESPACE::map<T1, T2>::iterator it = m2.begin(), ite = m2.end();
	for (int i = 1; it != ite; ++it)
	{
		it->second = i * 5;
		i++;
	}
	printDetails(m2);

	std::cout << "Copying a range of M2 into M3" << std::endl;
	it  = m2.begin();
	ite = m2.end();
	NAMESPACE::map<T1, T2> m3(it, --(--ite));
	printDetails(m3);
	
	gettimeofday(&exec_time, NULL);
	double end = exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << std::endl;
}