#include <iostream>
#include <string>
#include <deque>
#include "header/vector.hpp"
#include "header/stack.hpp"
// #if 1 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	#include <iterator>
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



int main(int argc, char** argv) {
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

	ft::stack<int> s;
	// ft::vector<int> i(5, 100);
	// ft::vector<int> j;
	// i.reserve(16);
	// i.push_back(3);
	// i.push_back(2);
	// i.push_back(-500);
	// i.push_back(1);
	// i.push_back(100);
	// ft::vector<int>::iterator it_b = i.begin();
	// ft::vector<int>::iterator it_b2 = i.end();
	// //ft::vector<int>::iterator it_e = i.end();// problema sprosit u Stasa!!!! where do i.end() - 0
	// //std::cout << *it_e << std::endl;
	// i.insert(it_b, it_b, it_b2);
	// std::cout << i.size() << std::endl;
	// std::cout << i.capacity() << std::endl;
	// for (int a = 0; a < i.size(); ++a)
	// {
	// 	std::cout << a << ": "<< i[a] << std::endl;
	// }

	std::cout << "_________________________" << std::endl;

	// std::vector<int> iv(5, 100);
	// std::vector<int> jv;
	// iv.reserve(16);
	// iv.push_back(3);
	// iv.push_back(2);
	// iv.push_back(-500);
	// iv.push_back(1);
	// iv.push_back(100);
	// std::vector<int>::iterator it = iv.begin();
	// std::vector<int>::iterator it2 = iv.end();
	// //std::cout << *it2 << std::endl;
	// iv.insert(it, it, it2);
	// std::cout << iv.size() << std::endl;
	// std::cout << iv.capacity() << std::endl;
	// for (int a = 0; a < iv.size(); ++a)
	// {
	// 	std::cout << a << ": "<< iv[a] << std::endl;
	// }
	return (0);
}