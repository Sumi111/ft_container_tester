#include "common.hpp"
#include <vector>

#define T1 int
#define T2 float
typedef _pair<const T1, T2> T3;


int		main(void)
{
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = exec_time.tv_sec + exec_time.tv_usec;

	NAMESPACE::map<T1, T2> m1;

	std::cout << "Creating MAP using insert" << std::endl;
	m1.insert(T3(1, 1.2));
	m1.insert(T3(2, 2.3));
	m1.insert(T3(3, 3.4));
	m1.insert(T3(4, 4.5));

	printDetails(m1);

	std::cout << "Inserting with same key" << std::endl;
	m1.insert(T3(4, 5.6));
	printDetails(m1);

	std::cout << "Inserting with range" << std::endl;
	NAMESPACE::map<T1, T2>::iterator it = m1.begin(), ite = m1.end();
	NAMESPACE::map<T1, T2> m2;
	m2.insert(it, ite);
	printDetails(m2);

	gettimeofday(&exec_time, NULL);
	double end = exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << std::endl;
}