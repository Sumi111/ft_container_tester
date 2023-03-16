#include "common.hpp"
#include <list>

#define T1 int
#define T2 int
typedef NAMESPACE::map<T1, T2>::value_type T3;
typedef NAMESPACE::map<T1, T2>::iterator ft_iterator;


template <typename MAP>
void	ft_bound(MAP &mp, const T1 &param)
{
	ft_iterator ite = mp.end(), it[2];
	_pair<ft_iterator, ft_iterator> ft_range;

	std::cout << "with key [" << param << "]:" << std::endl;
	it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
	ft_range = mp.equal_range(param);
	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0])) << std::endl;
	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1])) << std::endl;
	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
	std::cout << std::endl;
}


int		main(void)
{
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = exec_time.tv_sec + exec_time.tv_usec;

	std::list<T3> lst;
	for (int i = 0; i < 10; ++i)
		lst.push_back(T3(i + 1, (i + 1) * 10));

	NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
	printDetails(mp);


	mp.lower_bound(3)->second = 404;
	mp.upper_bound(7)->second = 842;
	printDetails(mp);


	ft_bound(mp, 5);
	ft_bound(mp, 7);

	printDetails(mp);

	gettimeofday(&exec_time, NULL);
	double end = exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << std::endl;
	return (0);
}
