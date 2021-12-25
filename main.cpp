#include <iostream>
#include <string>
#include <deque>
#include "header/vector.hpp"
#include "header/stack.hpp"
#include "header/map.hpp"
// #if 1 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	#include <iterator>
	#include <list>
	//namespace ft = std;
// #else
// 	#include <map.hpp>
// 	#include <stack.hpp>
// 	#include <vector.hpp>
// #endif

// #include <stdlib.h>

// #define MAX_RAM 4294967296
// #define BUFFER_SIZE 4096
// struct Buffer
// {
// 	int idx;
// 	char buff[BUFFER_SIZE];
// };


// #define COUNT (MAX_RAM / (int)sizeof(Buffer))

// template<typename T>
// class MutantStack : public ft::stack<T>
// {
// public:
// 	MutantStack() {}
// 	MutantStack(const MutantStack<T>& src) { *this = src; }
// 	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
// 	{
// 		this->c = rhs.c;
// 		return *this;
// 	}
// 	~MutantStack() {}

// 	typedef typename ft::stack<T>::container_type::iterator iterator;

// 	iterator begin() { return this->c.begin(); }
// 	iterator end() { return this->c.end(); }
// };



/*int main(int argc, char** argv) {
	// if (argc != 2)
	// {
	// 	std::cerr << "Usage: ./test seed" << std::endl;
	// 	std::cerr << "Provide a seed please" << std::endl;
	// 	std::cerr << "Count value:" << COUNT << std::endl;
	// 	return 1;
	// }
	// const int seed = atoi(argv[1]);
	// srand(seed);

	// ft::vector<std::string> vector_str;
	// ft::vector<int> vector_int;
	// ft::stack<int> stack_int;
	// ft::vector<Buffer> vector_buffer;
	// ft::stack<Buffer, std::deque<int> > stack_deq_buffer;
	// ft::map<int, int> map_int;

	// for (int i = 0; i < COUNT; i++)
	// {
	// 	vector_buffer.push_back(Buffer());
	// }

	// for (int i = 0; i < COUNT; i++)
	// {
	// 	const int idx = rand() % COUNT;
	// 	vector_buffer[idx].idx = 5;
	// }
	// ft::vector<Buffer>().swap(vector_buffer);

	// try
	// {
	// 	for (int i = 0; i < COUNT; i++)
	// 	{
	// 		const int idx = rand() % COUNT;
	// 		vector_buffer.at(idx);
	// 		std::cerr << "Error: THIS vector SHOULD BE EMPTY!!" <<std::endl;
	// 	}
	// }
	// catch(const std::exception& e)
	// {
	// 	//NORMAL ! :P
	// }
	
	// for (int i = 0; i < COUNT; ++i)
	// {
	// 	map_int.insert(ft::make_pair(rand(), rand()));
	// }

	// int sum = 0;
	// for (int i = 0; i < 10000; i++)
	// {
	// 	int access = rand();
	// 	sum += map_int[access];
	// }
	// std::cout << "should be constant with the same seed: " << sum << std::endl;

	// {
	// 	ft::map<int, int> copy = map_int;
	// }
	// MutantStack<char> iterable_stack;
	// for (char letter = 'a'; letter <= 'z'; letter++)
	// 	iterable_stack.push(letter);
	// for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	// {
	// 	std::cout << *it;
	// }
	// std::cout << std::endl;

	// ft::vector<int> i(10);
	// // ft::vector<int> j;
	// // i.reserve(16);
	// // i.push_back(3);
	// // i.push_back(2);
	// // i.push_back(-500);
	// // i.push_back(1);
	// // i.push_back(100);
	// ft::vector<int>::iterator it_b = i.begin();
	// ft::vector<int>::iterator it_b2 = i.end();
	// // //ft::vector<int>::iterator it_e = i.end() - 0;// problema sprosit u Stasa!!!! where do i.end() - 0
	// // //std::cout << *it_e << std::endl;
	// i.resize(4);
	// std::cout << i.size() << std::endl;
	// std::cout << i.capacity() << std::endl;
	// for (int a = 0; a < i.size(); ++a)
	// {
	// 	std::cout << a << ": "<< i[a] << std::endl;
	// }

	// std::cout << "_________________________" << std::endl;

	// std::vector<int> iv(10);
	// // std::vector<int> jv;
	// // iv.reserve(16);
	// // iv.push_back(3);
	// // iv.push_back(2);
	// // iv.push_back(-500);
	// // iv.push_back(1);
	// // iv.push_back(100);
	// std::vector<int>::iterator it = iv.begin();
	// std::vector<int>::iterator it2 = iv.end();
	// // //std::cout << *it2 << std::endl;
	// iv.resize(4);
	// std::cout << iv.size() << std::endl;
	// std::cout << iv.capacity() << std::endl;
	// for (int a = 0; a < iv.size(); ++a)
	// {
	// 	std::cout << a << ": "<< iv[a] << std::endl;
	// }
	//ft::map<int, int> a();
	return (0);
}*/

// #include "header/containers_test/srcs/map/common.hpp"

// #define T1 int
// #define T2 std::string
// typedef _pair<const T1, T2> T3;

// static int iter = 0;

// template <typename MAP, typename U>
// void	ft_erase(MAP &mp, U param)
// {
// 	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
// 	mp.erase(param);
// 	printSize(mp);
// }

// template <typename MAP, typename U, typename V>
// void	ft_erase(MAP &mp, U param, V param2)
// {
// 	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
// 	mp.erase(param, param2);
// 	printSize(mp);
// }

// int		main(void)
// {
// 	std::list<T3> lst;
// 	unsigned int lst_size = 10;
// 	for (unsigned int i = 0; i < lst_size; ++i)
// 		lst.push_back(T3(i, std::string((lst_size - i), i + 65)));
// 	TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
// 	printSize(mp);

// 	ft_erase(mp, ++mp.begin());

// 	ft_erase(mp, mp.begin());
// 	ft_erase(mp, --mp.end());

// 	ft_erase(mp, mp.begin(), ++(++(++mp.begin())));
// 	ft_erase(mp, --(--(--mp.end())), --mp.end());

// 	mp[10] = "Hello";
// 	mp[11] = "Hi there";
// 	printSize(mp);
// 	ft_erase(mp, --(--(--mp.end())), mp.end());

// 	mp[12] = "ONE";
// 	mp[13] = "TWO";
// 	mp[14] = "THREE";
// 	mp[15] = "FOUR";
// 	printSize(mp);
// 	ft_erase(mp, mp.begin(), mp.end());

// 	return (0);
// }