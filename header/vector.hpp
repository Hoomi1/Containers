#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <iterator>

namespace ft
{
	template <typename T>
	class VectorIterator
	{
		public:
			typedef T					value_type;
			typedef value_type*			pointer;
			typedef value_type const*	const_pointer;
			typedef value_type&			reference;
			typedef value_type const&	const_reference;
		private:
			pointer m_Ptr;
		public:
			VectorIterator() : m_Ptr(0) {}

			virtual ~VectorIterator() {}

			VectorIterator(const VectorIterator &other) : m_Ptr(other.m_Ptr) {}

			VectorIterator &operator = (const VectorIterator &other)
			{
				if (this != &other)
				{
					this->m_Ptr = other.m_Ptr;
				}
				return (*this);
			}

			VectorIterator(pointer ptr) : m_Ptr(ptr){}

			bool operator == (const VectorIterator &other) const
			{
				return (this->m_Ptr == other.m_Ptr);
			}

			bool operator != (const VectorIterator &other) const
			{
				return (this->m_Ptr != other.m_Ptr);
			}
			
			reference operator * ()
			{
				return (*this->m_Ptr);
			}

			const_reference operator * () const
			{
				return (*this->m_Ptr);
			}

			pointer operator -> ()
			{
				return (this->m_Ptr);
			}

			const_pointer operator -> () const
			{
				return (this->m_Ptr);
			}

			VectorIterator &operator ++ ()
			{
				++this->m_Ptr;
				return (*this);
			}

			VectorIterator operator ++ (int)
			{
				VectorIterator vi(*this);
				++this->m_Ptr;
				return (vi);
			}

			//*a++

			VectorIterator &operator -- ()
			{
				--this->m_Ptr;
				return (*this);
			}

			VectorIterator operator -- (int)
			{
				VectorIterator vi(*this);
				--this->m_Ptr;
				return (vi);
			}

			//*a--

			VectorIterator &operator + (int _num) const
			{
				this->m_Ptr += _num;
				return (*this->m_Ptr);
			}

			VectorIterator &operator - (int _num) const
			{
				this->m_Ptr -= _num;
				return (*this->m_Ptr);
			}

			bool &operator > (const VectorIterator &other) const
			{
				return (this->m_Ptr > other.m_Ptr);
			}

			bool &operator < (const VectorIterator &other) const
			{
				return (this->m_Ptr < other.m_Ptr);
			}

			bool &operator >= (const VectorIterator &other) const
			{
				return (this->m_Ptr >= other.m_Ptr);
			}

			bool &operator <= (const VectorIterator &other) const
			{
				return (this->m_Ptr <= other.m_Ptr);
			}

			VectorIterator operator += (int _num)
			{
				this->m_Ptr += _num;
				return (*this);
			}

			VectorIterator operator -= (int _num)
			{
				this->m_Ptr -= _num;
				return (*this);
			}

			reference operator [] (int pos)
			{
				return (*(this->m_arr + pos));
			}

			const_reference operator [] (int pos) const
			{
				return (*(this->m_arr + pos));
			}
	};


	template < class T, class Alloc = std::allocator<T> >
	class Vector
	{
		public:
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef VectorIterator<value_type>					iterator;
			typedef VectorIterator<const value_type>			const_iterator;
								//reverse_iterator;//
			typedef typename allocator_type::size_type			size_type;

		private:
			allocator_type	m_alloc;
			pointer			m_arr;
			size_type		m_size;
			size_type		m_capacity;

		public:
		/////
			Vector(const allocator_type& alloc = allocator_type()) :
			m_alloc(alloc),
			m_arr(new value_type[0]),
			m_size(0),
			m_capacity(0){}
		/////
			Vector(size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type()) :
				m_alloc(alloc),
				m_arr(new value_type[0]),
				m_size(0),
				m_capacity(1)
			{
				m_arr = m_alloc.allocate(n);
				if (n > this->m_capacity)
					reserve(n);
				for (int i = this->m_size; i < n; ++i)
				{
					this->m_arr[i] = value_type(val);
				}
				this->m_size = n;
			}

		/////				custom				/////
			// Vector(iterator first, iterator last,
			// 			const allocator_type& alloc = allocator_type()) :
			// m_alloc(alloc)
			// {
				
			// }
		/////				custom				/////

			Vector(const Vector &other) :
			m_alloc(other.m_alloc),
			m_arr(new value_type[this->m_capacity]),///////////
			m_size(other.m_size),
			m_capacity(other.m_capacity)
			{
				for (int i = 0; i < other.m_size; ++i)
					this->m_arr[i] = other.m_arr[i];
			}
		/////
			~Vector()
			{
					delete[] m_arr;
			}
		/////
			Vector &operator = (const Vector &other)
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

			iterator begin()
			{
				return (iterator(this->m_arr));
			}

			const_iterator begin() const
			{
				return (const_iterator(this->m_arr));
			}

			iterator end()
			{
				return (iterator(&(this->m_arr[this->m_size])));
			}

			const_iterator end() const
			{
				return (const_iterator(&(this->m_arr[this->m_size])));
			}

			//rbegin
			//rend
			
			size_type size() const
			{
				return (this->m_size);
			}

			size_type max_size()const
			{
				return (4611686018427387903);
			}

			void resize(size_type n, const value_type &value = value_type())
			{
				if (n > this->m_capacity)
					reserve(n);
				for (int i = this->m_size; i < n; ++i)
				{
					this->m_arr[i] = T(value);
				}
				this->m_size = n;
			}

			size_type capacity() const
			{
				return (this->m_capacity);
			}

			bool empty() const
			{
				if (m_size >= 1)
					return (false);
				return (true);
			}

			void reserve(size_type new_cap)
			{
				pointer new_arr = new T[new_cap];
				for (int i = 0; i < this->m_size;++i)
					new_arr[i] = this->m_arr[i];
				this->m_capacity = new_cap;
				delete[] m_arr;
				this->m_arr = new_arr;
			}

			reference operator [] (size_type pos)
			{
				return (*(this->m_arr + pos));
			}

			reference at (size_type n)
			{
				if (n < 0 || n >= this->m_size)
					throw std::out_of_range("vector");
				return (reference(*(this->m_arr + n)));
			}

			const_reference at (size_type n) const
			{
				if (n < 0 || n >= this->m_size)
					throw std::out_of_range("vector");
				return (const_reference(*(this->m_arr + n)));
			}

			reference front()
			{
				return (*(this->m_arr + 0));
			}

			const_reference front() const
			{
				return (*(this->m_arr + 0));
			}

			reference back()
			{
				return (*(this->m_arr + (this->m_size - 1)));
			}

			const_reference back() const
			{
				return (*(this->m_arr + (this->m_size - 1)));
			}

			template <class InputIterator>
			void assign (InputIterator first, InputIterator last)
			{

			}

			void assign (size_type n, const value_type& val)
			{

			}
			
			//assign

			void push_back(const_reference value)
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