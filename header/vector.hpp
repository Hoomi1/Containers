#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <alloca.h>
namespace ft
{
	template <typename T>
	class Vector
	{
		private:
			T		*_arr;
			size_t	_sz;
			size_t	_capacity;
		public:
			Vector() : _arr(new T[0]), _sz(0), _capacity(0) {};

			~Vector()
			{
				delete[] _arr;
			}

			Vector(const Vector<T> &other)
			{
				*this = other;
			}

			Vector &operator = (const Vector<T> &other)
			{
				return (*this);
			}


	};
}

#endif