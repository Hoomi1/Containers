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

	ft::vector<int> i(10);
	// ft::vector<int> j;
	// i.reserve(16);
	// i.push_back(3);
	// i.push_back(2);
	// i.push_back(-500);
	// i.push_back(1);
	// i.push_back(100);
	ft::vector<int>::iterator it_b = i.begin();
	ft::vector<int>::iterator it_b2 = i.end();
	// //ft::vector<int>::iterator it_e = i.end() - 0;// problema sprosit u Stasa!!!! where do i.end() - 0
	// //std::cout << *it_e << std::endl;
	i.resize(4);
	std::cout << i.size() << std::endl;
	std::cout << i.capacity() << std::endl;
	for (int a = 0; a < i.size(); ++a)
	{
		std::cout << a << ": "<< i[a] << std::endl;
	}

	std::cout << "_________________________" << std::endl;

	std::vector<int> iv(10);
	// std::vector<int> jv;
	// iv.reserve(16);
	// iv.push_back(3);
	// iv.push_back(2);
	// iv.push_back(-500);
	// iv.push_back(1);
	// iv.push_back(100);
	std::vector<int>::iterator it = iv.begin();
	std::vector<int>::iterator it2 = iv.end();
	// //std::cout << *it2 << std::endl;
	iv.resize(4);
	std::cout << iv.size() << std::endl;
	std::cout << iv.capacity() << std::endl;
	for (int a = 0; a < iv.size(); ++a)
	{
		std::cout << a << ": "<< iv[a] << std::endl;
	}
	return (0);
}*/

//#include "header/containers_test/srcs/vector/common.hpp"

class B {
public:
	char *l;
	int i;
	B():l(nullptr), i(1) {};
	B(const int &ex) {
		this->i = ex;
		this->l = new char('a');
	};
	virtual ~B() {
		delete this->l;
		this->l = nullptr;
	};
};

class A : public B {
public:
	A():B(){};
	A(const B* ex){
		this->l = new char(*(ex->l));
		this->i = ex->i;
		if (ex->i == -1) throw "n";
	}
	~A() {
		delete this->l;
		this->l = nullptr;
	};
};

std::vector<int> insert_test_1() {
    std::vector<int> v;
	ft::vector<int> vector;
    vector.assign(26000000, 1);
   // g_start1 = timer();
    v.push_back(*(vector.insert(vector.end() - 8000000, 44)));
    //g_end1 = timer();
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    std::unique_ptr<B> k2(new B(3));
    std::unique_ptr<B> k3(new B(4));
    std::unique_ptr<B> k4(new B(-1));
    ft::vector<A> vv;
    ft::vector<B*> v1;

    v1.push_back(&(*k2));
    v1.push_back(&(*k3));
    v1.push_back(&(*k4));
    try
	{
		vv.insert(vv.begin(), v1.begin(), v1.end());
	}
    catch (...) {
		v.push_back(vv.size());
		v.push_back(vv.capacity());
    }
    return v;
}

// std::vector<int> swap_test() {
//     std::vector<int> vector;
// 	std::vector<int> v;
//     vector.assign(11000000, 11);
//     std::vector<int> tmp(5000000, 5), tmp2(10000000, 10), tmp3(15000000, 15), tmp4(30000000, 30);
//     //g_start1 = timer();
//     v.push_back(vector[2]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     long *adr1 = reinterpret_cast<long *>(&vector);
//     long *adr2 = reinterpret_cast<long *>(&tmp);
//     vector.swap(tmp);
//     if (reinterpret_cast<long *>(&vector) == adr1 && reinterpret_cast<long *>(&tmp) == adr2)
//     	v.push_back(1);
//     v.push_back(vector[2]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     vector.swap(tmp3);
//     v.push_back(vector[2]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     std::swap(vector, tmp2);
//     v.push_back(vector[2]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     std::swap(vector, tmp4);
//     //g_end1 = timer();
//     v.push_back(vector[2]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     return v;
// }


// std::vector<int> push_back_test() {
//     std::vector<int> v;
// 	ft::vector<int> vector;
//     //g_start1 = timer();
//     for (int i = 0; i < 55000000; ++i)
//         vector.push_back(i);
//     //g_end1 = timer();
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     return v;
// }


std::vector<int> insert_std_test() {
	std::vector<int> vector;
	std::vector<int> v;
	std::vector<int> tmp;
	tmp.assign(26, 1);
	vector.assign(42, 7);
	//g_start1 = timer();
	vector.insert(vector.begin(), tmp.begin(), tmp.end());
	//g_end1 = timer();
	for (size_t i = 0; i < tmp.size(); ++i) {
		v.push_back(vector[i]);
	}
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

std::vector<int> insert_test_2(){
	
    std::vector<int> v;
	std::vector<int> vector;
    std::vector<int> tmp;
    tmp.assign(26000000, 1);
    vector.assign(22000000, 1);
   // g_start1 = timer();
    vector.insert(vector.end() - 14000000, tmp.begin(), tmp.end());
    // g_end1 = timer();
    v.push_back(vector[3]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

// std::vector<int> constructor_test() {
	
//     std::vector<int> v;
// 	std::vector<int> vector;
//     std::vector<int> tmp0(vector);
//     std::vector<int> tmp(10000000, 4), tmp2(10000000, 5);
//     tmp = tmp2;
//     std::vector<int> tmp3(tmp);
//     //g_start1 = timer();
//     std::vector<int> tmp4(tmp.begin(), tmp.end());
//     //g_end1 = timer();
//     v.push_back(tmp4.size());
//     v.push_back(tmp4.capacity());
//     v.push_back(tmp[2]);
//     v.push_back(tmp3[2]);
//     v.push_back(tmp4[2]);
//     try { std::vector<int> tmp5(-1, -1); }
//     catch (std::exception &e) { v.push_back(1); }
//     return v;
// }

int main ()
{
	std::vector<int> v = insert_test_1();
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " ";
	}
	
}

// #define TESTED_TYPE int

// int		main(void)
// {
// 	std::list<TESTED_TYPE> lst;
// 	std::list<TESTED_TYPE>::iterator lst_it;
// 	for (int i = 1; i < 5; ++i)
// 		lst.push_back(i * 3);

// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(lst.begin(), lst.end());
// 	printSize(vct);

// 	lst_it = lst.begin();
// 	for (int i = 1; lst_it != lst.end(); ++i)
// 		*lst_it++ = i * 5;
// 	vct.assign(lst.begin(), lst.end());
// 	printSize(vct);

// 	vct.insert(vct.end(), lst.rbegin(), lst.rend());
// 	printSize(vct);
// 	return (0);
// }

// #define TESTED_TYPE int

// int		main(void)
// {
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(10);
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;

// 	for (unsigned long int i = 0; i < vct.size(); ++i)
// 		vct[i] = (vct.size() - i) * 3;
// 	printSize(vct);

// 	vct2.insert(vct2.end(), 42);
// 	vct2.insert(vct2.begin(), 2, 21);
// 	printSize(vct2);

// 	vct2.insert(vct2.end() - 2, 42);
// 	printSize(vct2);

// 	vct2.insert(vct2.end(), 2, 84);
// 	printSize(vct2);

// 	vct2.resize(4);
// 	printSize(vct2);

// 	vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
// 	vct.clear();
// 	printSize(vct2);

// 	printSize(vct);
// 	return (0);
// }