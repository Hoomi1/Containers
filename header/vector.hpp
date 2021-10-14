#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <alloca.h>
// namespace ft
// {
	template <typename T>
	class Vector
	{
		private:
			T		*m_arr;
			size_t	m_size;
			size_t	m_capacity;
		public:
			Vector() : m_arr(new T[0]), m_size(0), m_capacity(1) {}

			~Vector()
			{
					delete[] m_arr;
			}

			Vector(const Vector<T> &other) :
			m_arr(new T[this->m_capacity]),
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
					this->m_arr = new T[m_capacity];
				}
				for (int i = 0; i < other.m_size; ++i)
					this->m_arr[i] = other.m_arr[i];
				
				this->m_size = other.m_size;

				return (*this);
			}

			void reserve(size_t new_cap)
			{
				T *new_arr = new T[new_cap];
				for (int i = 0; i < this->m_size;++i)
					new_arr[i] = this->m_arr[i];
				this->m_capacity = new_cap;
				delete[] m_arr;
				this->m_arr = new_arr;
			}

			void resize(size_t n, const T &value = T())
			{
				if (n > this->m_capacity)
					reserve(n);
				for (int i = this->m_size; i < n; ++i)
				{
					this->m_arr[i] = T(value);
				}
				this->m_size = n;
			}

			size_t size() const
			{
				return (this->m_size);
			}

			size_t max_size()const
			{
				return (4611686018427387903);
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
				this->m_size = 0;
				this->m_arr = 0;
			}

			void push_back( const T& value)
			{
				if (this->m_size >= this->m_capacity)
					reserve(this->m_capacity * 2);
				this->m_arr[m_size] = T(value);
				++m_size;
			}

			void pop_back()
			{
				--this->m_size;
			}

			T* data()
			{
				return (this->m_arr);
			}



//////////////////////////////////////////////////////
			T &operator [] (size_t pos)
			{
				return (this->m_arr[pos]);
			}
	};
//}

#endif