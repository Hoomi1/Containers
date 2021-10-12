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
			T		*m_arr;
			size_t	m_size;
			size_t	m_capacity;
		public:
			Vector() : m_arr(new T[0]), m_size(0), m_capacity(0) {};

			~Vector()
			{
				if (_size > 1)
					delete[] m_arr;
				delete m_arr;
			}

			Vector(const Vector<T> &other)
			{
				*this = other;
			}

			Vector &operator = (const Vector<T> &other)/////
			{
				return (*this);
			}

			void resize(size_t n, const T &value = T())//////
			{

			}

			size_t size() const
			{
				return (this->m_size);
			}

			size_t capacity() const
			{
				return (this->m_capacity);
			}

			bool empty() const
			{
				if (m_size >= 1)
					return (false);
				return (true);
			}
	};
}

#endif