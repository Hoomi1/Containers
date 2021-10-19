#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <iterator>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class Vector
	{
		public:
			typedef T														value_type;
			typedef Alloc													allocator_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef ft::random_access_iterator_tag<value_type>				iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef typename allocator_type::size_type						size_type;
			
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

			template <class InputIterator>
			Vector(InputIterator first, InputIterator last)
			{

			}

			//begin
			//end
			//rbegin
			//rend
			
			size_t size() const
			{
				return (this->m_size);
			}

			size_t max_size()const
			{
				return (4611686018427387903);
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

			void reserve(size_t new_cap)
			{
				T *new_arr = new T[new_cap];
				for (int i = 0; i < this->m_size;++i)
					new_arr[i] = this->m_arr[i];
				this->m_capacity = new_cap;
				delete[] m_arr;
				this->m_arr = new_arr;
			}

			T &operator [] (size_t pos)
			{
				return (this->m_arr[pos]);
			}

			//at
			//front
			//back
			//assign

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

			//insert
			//erase
			//swap

			void clear()
			{
				this->m_size = 0;
				this->m_arr = 0;
			}
	};
}

#endif