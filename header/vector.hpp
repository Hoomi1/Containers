#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <iterator>
#include "UtilsIterator/iterator.hpp"

namespace ft
{
	template <typename T>
	class random_access_iterator 
	{
		public:
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;
			typedef	T* pointer;
			typedef	T& reference;
		private:
			pointer m_Ptr;
		public:
			random_access_iterator() : m_Ptr(0) {}

			virtual ~random_access_iterator() {}

			random_access_iterator(const random_access_iterator &other) : m_Ptr(other.m_Ptr) {}

			random_access_iterator &operator = (const random_access_iterator &other)
			{
				if (this != &other)
				{
					this->m_Ptr = other.m_Ptr;
				}
				return (*this);
			}

			random_access_iterator(pointer ptr) : m_Ptr(ptr){}

			bool operator==(const random_access_iterator &other) const
			{
				return (this->m_Ptr == other.m_Ptr);
			}

			bool operator!=(const random_access_iterator &other) const
			{
				return (this->m_Ptr != other.m_Ptr);
			}

			reference operator*() const
			{
				return (*this->m_Ptr);
			}

			pointer operator->() const
			{
				return (this->m_Ptr);
			}

			random_access_iterator &operator++()
			{
				++(this->m_Ptr);
				return (*this);
			}

			random_access_iterator operator++(int)
			{
				random_access_iterator vi(*this);
				++this->m_Ptr;
				return (vi);
			}

			//*a++

			random_access_iterator &operator--()
			{
				--this->m_Ptr;
				return (*this);
			}

			random_access_iterator operator--(int)
			{
				random_access_iterator vi(*this);
				--this->m_Ptr;
				return (vi);
			}

			//*a--

			random_access_iterator operator+(difference_type _num) const
			{
				return (this->m_Ptr + _num);
			}

			random_access_iterator operator-(difference_type _num) const
			{
				return (this->m_Ptr - _num);
			}

			difference_type operator-(const random_access_iterator &it)
			{
				return (this->m_Ptr - it.m_Ptr);
			}
			bool &operator>(const random_access_iterator &other) const
			{
				return (this->m_Ptr > other.m_Ptr);
			}

			bool &operator<(const random_access_iterator &other) const
			{
				return (this->m_Ptr < other.m_Ptr);
			}

			bool &operator>=(const random_access_iterator &other) const
			{
				return (this->m_Ptr >= other.m_Ptr);
			}

			bool &operator<=(const random_access_iterator &other) const
			{
				return (this->m_Ptr <= other.m_Ptr);
			}

			random_access_iterator &operator+=(difference_type _num)
			{
				this->m_Ptr += _num;
				return (*this);
			}

			random_access_iterator &operator-=(difference_type _num)
			{
				this->m_Ptr -= _num;
				return (*this);
			}

			reference operator [](difference_type pos) const
			{
				return (*(this->m_arr + pos));
			}
			
	};

	template <typename T>
	ft::random_access_iterator<T> operator+(typename ft::random_access_iterator<T>::difference_type _num,
											ft::random_access_iterator<T> it)
	{
		ft::random_access_iterator<T> temp(it);
		temp += _num;
		return (temp);
	}

	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;

			typedef ft::random_access_iterator<value_type>			iterator;
			typedef ft::random_access_iterator<const value_type>	const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef typename allocator_type::size_type			size_type;

		private:
			allocator_type	m_alloc;
			pointer			m_arr;
			size_type		m_size;
			size_type		m_capacity;

		public:
		/////
			explicit vector(const allocator_type& alloc = allocator_type()) :
			m_alloc(alloc),
			m_size(0),
			m_capacity(1)
			{
				this->m_arr = this->m_alloc.allocate(0);
			}
		/////
			explicit vector(size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type()) :
				m_alloc(alloc),
				m_size(0),
				m_capacity(1)
			{
				m_arr = m_alloc.allocate(n);
				if (n > this->m_capacity)
					reserve(n);
				for (int i = this->m_size; i < n; ++i)
					this->m_arr[i] = value_type(val);
				this->m_size = n;
			}
		/////
			template <class InputIterator>
			vector(InputIterator first, InputIterator last,
						const allocator_type& alloc = allocator_type(),
						typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) :
			m_alloc(alloc),
			m_size(0)
			{
				for (InputIterator it = first; it != last; ++it)
					this->m_size++;
				this->m_capacity = this->m_size;
				this->m_arr = this->m_alloc.allocate(this->m_capacity);
				int i = 0;
				for (InputIterator it = first; it != last; ++i, ++it)
					this->m_alloc.construct(&this->m_arr[i], *it);
			}
		/////
			vector(const vector &other) :
			m_alloc(other.m_alloc),
			m_size(other.m_size),
			m_capacity(other.m_capacity)
			{
				this->m_arr = (this->m_alloc.allocate(this->m_capacity));
				for (int i = 0; i < other.m_size; ++i)
					this->m_alloc.construct(&this->m_arr[i], other.m_arr[i]);
			}
		/////
			~vector()
			{
				clear();
				if (this->m_capacity != 0)
					this->m_alloc.deallocate(this->m_arr, this->m_capacity);
			}
		/////
			vector &operator = (const vector &other)
			{
				if (*this != other)
				{
					for (int i = 0; i < this->m_size; ++i)
						this->m_alloc.destroy(&this->m_arr[i]);
					if (other.m_capacity > this->m_capacity)
					{
						this->m_alloc.deallocate(this->m_arr, this->m_capacity);
						this->m_capacity = other.m_size;
						this->m_arr = this->m_alloc.allocate(this->m_capacity);
					}
					for (int i = 0; i < other.m_size; ++i)
						this->m_alloc.construct(&this->m_arr[i], other.m_arr[i]);
					this->m_size = other.m_size;
				}
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

			reverse_iterator rbegin()
			{
				return (reverse_iterator(this->end()));
			}

			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(this->end()));
			}

			reverse_iterator rend()
			{
				return (reverse_iterator(this->begin()));
			}

			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(this->begin()));
			}
			
			size_type size() const
			{
				return (this->m_size);
			}

			size_type max_size()const
			{
				return (allocator_type().max_size());
			}

			void resize(size_type n, const value_type &value = value_type())
			{
				if (n > this->m_capacity)
					reserve(n);
				for (int i = this->m_size; i < n; ++i)
				{
					this->m_arr[i] = value_type(value);
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
				if (this->m_capacity >= new_cap)
					return ;
				if (new_cap > max_size())
					throw std::length_error("vector");
				pointer new_arr = this->m_alloc.allocate(new_cap);
				for (int i = 0; i < this->m_size;++i)
					this->m_alloc.construct(&new_arr[i], this->m_arr[i]);
				this->m_capacity = new_cap;
				for (int i = 0; i < this->m_size; ++i)
					this->m_alloc.destroy(&this->m_arr[i]);
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

			void assign (size_type n, const value_type& val)
			{
				for (int i = 0; i < this->m_size; ++i)
						this->m_alloc.destroy(&this->m_arr[i]);
				if (n > this->m_capacity)
				{
					this->m_alloc.deallocate(this->m_arr, this->m_capacity);
					this->m_capacity = n;
					this->m_arr = this->m_alloc.allocate(n);
				}
				for (int i = 0; i < n; ++i)
					this->m_alloc.construct(&this->m_arr[i], val);
				this->m_size = n;
			}

			template <class InputIterator>
			void assign (InputIterator first, InputIterator last,
						typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)////
			{
				size_type new_size = 0;

				reserve(last - first);
				for (int i = 0; i < this->m_size; ++i)
					this->m_alloc.destroy(&this->m_arr[i]);
				for (InputIterator it = first; it != last; ++it)
					new_size++;
				if (this->m_capacity < new_size)
				{
					this->m_alloc.deallocate(this->m_arr, this->m_capacity);
					this->m_capacity = new_size;
					this->m_arr = this->m_alloc.allocate(this->m_capacity);
				}
				int i = 0;
				for (InputIterator it = first; it != last; ++it, ++i)
					this->m_alloc.construct(&this->m_arr[i], *it);
				this->m_size = new_size;
			}

			void push_back(const_reference value)
			{
				if (this->m_size >= this->m_capacity)
					reserve(this->m_capacity * 2);
				this->m_arr[m_size] = value_type(value);
				++m_size;
			}

			void pop_back()
			{
				--this->m_size;
			}
			///////////////////////////////////////////////////////////////////
			iterator insert (iterator position, const value_type& val)////////
			{
				// if (this->m_size + 1 > this->m_capacity)
				// 	reserve(this->m_capacity * 2);
				// pointer p = &(*position);
				// for (iterator it = ; i < this->m_size + 1; ++i)
				// {
				// 	this->m_alloc.destroy((&(*position) + i + 1));
				// 	this->m_alloc.construct(&(*position) + i + 1, *(&(*position) + i));
				// }
				// this->m_alloc.destroy(&(*p));
				// this->m_alloc.construct(&(*p), val);
				// this->m_size += 1;
				// return (iterator(p));
			}

			void insert (iterator position, size_type n, const value_type& val)///////
			{

			}

			template <class InputIterator>///////
			void insert (iterator position, InputIterator first, InputIterator last,
						typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			{

			}

			iterator erase (iterator position)
			{
				pointer p = &(*position);
				this->m_alloc.destroy(&(*p));
				for (int i = 0; i < this->m_size; ++i)
					this->m_alloc.construct(&(*position) + i, *(&(*position) + i + 1));
				this->m_size -= 1;
				return(iterator(p));
			}

			iterator erase (iterator first, iterator last)
			{
				pointer p = &(*first);
				int sum = 0;
				for (iterator it = first; it != last; ++it)
				{
					this->m_alloc.destroy(&(*it));
					sum += 1;
				}
				for (int i = 0; i < this->m_size; ++i)
					this->m_alloc.construct(&(*first) + i, *(&(*last) + i));
				this->m_size -= sum;
				return (iterator(p));
			}

			//insert
			///////////////////////////////////////////////////////////////////
			void swap (vector& x)
			{
				allocator_type	m_alloc_new;
				pointer			m_arr_new;
				size_type		m_size_new;
				size_type		m_capacity_new;

				m_alloc_new = this->m_alloc;
				m_arr_new = this->m_arr;
				m_size_new = this->m_size;
				m_capacity_new = this->m_capacity;

				this->m_alloc = x.m_alloc;
				this->m_arr = x.m_arr;
				this->m_size = x.m_size;
				this->m_capacity = x.m_capacity;

				x.m_alloc = m_alloc_new;
				x.m_arr = m_arr_new;
				x.m_size = m_size_new;
				x.m_capacity = m_capacity_new;
			}

			void clear()
			{
				for (int i = 0; i < this->m_size; ++i)
					this->m_alloc.destroy(&this->m_arr[i]);
				this->m_size = 0;
			}

			allocator_type get_allocator() const
			{
				return (this->m_alloc);
			}
	};

	template<class T, class Alloc>
	bool operator==(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		if (lhs.size() == rhs.size())
		{
			typename ft::vector<T>::const_iterator it1 = lhs.begin();//////xz kak nado
			typename ft::vector<T>::const_iterator it2 = rhs.begin();/////xz kak nado
			for (; it1 != lhs.end(); ++it1, ++it2)
			{
				if (*it1 != *it2 || it2 == rhs.end())
					return (false);
			}
			return (true);
		}
		else
			return (false);
	}

	template<class T, class Alloc>
	bool operator!=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		if (!(lhs == rhs))
			return (true);
		else
			return (false);
	}

	template<class T, class Alloc>
	bool operator<(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template<class T, class Alloc>
	bool operator<=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}

	template<class T, class Alloc>
	bool operator>(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template<class T, class Alloc>
	bool operator>=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}

	template< class T, class Alloc >
	void swap(vector<T,Alloc>& lhs,vector<T,Alloc>& rhs)
	{
		lhs.swap(rhs);
	}
}

#endif