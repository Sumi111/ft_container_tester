#include "common.hpp"
#include <vector>

#define T1 int
#define T2 int
typedef _pair<const T1, T2> T3;

template <typename MAP>
void	my_find(MAP m, T1 const &k)
{
	typename MAP::iterator ret = m.find(k);
	NAMESPACE::map<T1, T2>::iterator ite = m.end();

	if (ret != ite)
		std::cout << "key: " << ret->first << " | value: " << ret->second << std::endl;
	else
		std::cout << "not found : Returned end()" << std::endl;
}

int		main(void)
{
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = exec_time.tv_sec + exec_time.tv_usec;

	std::vector<T3> v1;
	unsigned int v1_size = 5;
	for (unsigned int i = 0; i < v1_size; ++i)
		v1.push_back(T3(v1_size - i, (v1_size - i) * 10));

	std::cout << "Creating MAP" << std::endl;
	NAMESPACE::map<T1, T2> m1(v1.begin(), v1.end());
	printDetails(m1);

	my_find(m1, 3);
	my_find(m1, 9);

	gettimeofday(&exec_time, NULL);
	double end = exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << std::endl;
}