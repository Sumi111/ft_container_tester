#include "common.hpp"
#include <vector>

#define T1 int
#define T2 std::string
typedef _pair<const T1, T2> T3;


int		main(void)
{
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = exec_time.tv_sec + exec_time.tv_usec;

	NAMESPACE::map<T1, T2> m1;
	std::cout << "Creating MAP using insert" << std::endl;
	m1.insert(T3(1, "hello"));
	m1.insert(T3(2, "there"));
	m1.insert(T3(3, "good"));
	m1.insert(T3(4, "luck"));
	printDetails(m1);

	std::cout << "Erase using key" << std::endl;
	m1.erase(2);
	printDetails(m1);

	std::cout << "Erase using range" << std::endl;
	NAMESPACE::map<T1, T2>::iterator it = m1.begin(), ite = m1.end();
	m1.erase(++it, ite);
	printDetails(m1);

	std::cout << "Erase using position" << std::endl;
	m1.erase(m1.begin());
	printDetails(m1);


	gettimeofday(&exec_time, NULL);
	double end = exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << std::endl;
}