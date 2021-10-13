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
			Vector() : m_arr(new T[0]), m_size(0), m_capacity(0) {}

			~Vector()
			{
				if (m_size > 1)
					delete[] m_arr;
				delete m_arr;
			}

			Vector(const Vector<T> &other) :
			m_arr(new T[m_capasity]),
			m_size(other.m_size),
			m_capacity(other.m_capacity)
			{
				for (int i = 0; i < other.m_size; ++i)
					this->m_arr[i] = other.m_arr[i];
			}

			Vector &operator = (const Vector<T> &other)
			{
				if (other.m_size > this->m_size)
				{
					delete[] this->m_arr;
					this->m_capacity = other.m_size * 2;
					this->m_arr = new T[capacity];
				}
				for (int i = 0; i < other.m_size; ++i)
					this->m_arr[i] = other.m_arr[i];
				
				this->m_size = other.m_size;

				return (*this);
			}

			Vector(size_t new_size)//////////
			{

			}

			Vector(size_t new_size, int index)///////////
			{

			}

			void reserve(size_t new_cap)
			{
				T *new_arr = new T[new_cap];
				for (int i = 0; i < this->m_size;++i)
					new_arr[i] = this->m_arr[i];
				this->capacity = new_cap;
				delete[] m_arr;
				this->m_arr = new_arr;
			}

			void resize(size_t n, const T &value = T())//////
			{
				if (n > this->capacity)
					reserve(n);
				
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

			void clear()
			{
				// for (int i = 0; i < m_size; ++i)
				// 	(reinterpret_cast<T*>(m_arr)[i]).~T();
				this->m_size = 0;
				this->m_capacity = 0;
				this->m_arr = 0;
			}
	};
}

#endif