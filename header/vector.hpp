#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "UtilsIterator/iterator.hpp"
#include "UtilsIterator/random_access_iterator.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T														value_type;
			typedef Alloc													allocator_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef ft::random_access_iterator<value_type>					iterator;
			typedef ft::random_access_iterator<const value_type>			const_iterator;
			typedef ft::reverse_iterator<iterator>							reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef typename allocator_type::size_type						size_type;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;

		private:
			allocator_type	m_alloc;
			pointer			m_arr;
			size_type		m_size;
			size_type		m_capacity;

		public:
		/////
			explicit vector(const allocator_type& alloc = allocator_type()) :
			m_alloc(alloc),
			m_arr(NULL),
			m_size(0),
			m_capacity(0) {}
		/////
			explicit vector(size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type()) :
				m_alloc(alloc),
				m_size(n),
				m_capacity(n)
			{
				m_arr = m_alloc.allocate(n);
				for (size_type i = 0; i < n; ++i)
					this->m_alloc.construct(&this->m_arr[i], val);
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
			m_arr(NULL),
			m_size(0),
			m_capacity(0)
			{
				reserve(other.m_capacity);
				try
				{
					std::uninitialized_copy(other.begin(), other.end(), this->m_arr);
				}
				catch(...)
				{
					this->m_alloc.deallocate(this->m_arr,this->m_capacity);
					throw;
				}
				this->m_size = other.m_size;
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
					for (size_type i = 0; i < this->m_size; ++i)
						this->m_alloc.destroy(&this->m_arr[i]);
					if (other.m_capacity > this->m_capacity)
					{
						this->m_alloc.deallocate(this->m_arr, this->m_capacity);
						this->m_capacity = other.m_capacity;
						this->m_arr = this->m_alloc.allocate(this->m_capacity);
					}
					for (size_type i = 0; i < other.m_size; ++i)
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
				return (iterator(m_arr + m_size));
			}

			const_iterator end() const
			{
				return (const_iterator(this->m_arr + this->m_size));
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
				if (this->m_size > n)
				{
					for (size_type i = 0; i < this->m_size; ++i)
						this->m_alloc.destroy(&this->m_arr[i]);
					this->m_size = n;
					for (size_type i = 0; i < this->m_size; ++i)
					{
						this->m_alloc.construct(&m_arr[i], m_arr[i]);
					}
				}
				if (n > this->m_capacity)
					reserve(n);
				for (size_type i = this->m_size; i < n; ++i)
					this->m_alloc.construct(&m_arr[i], value);
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
				try
				{
					std::uninitialized_copy(this->begin(), this->end(), new_arr);
				}
				catch(...)
				{
					this->m_alloc.deallocate(this->m_arr,new_cap);
					throw;
				}
				for (size_type i = 0; i < this->m_size; ++i)
					this->m_alloc.destroy(this->m_arr + i);
				if (this->m_size != 0)
				this->m_alloc.deallocate(this->m_arr,this->m_capacity);
				this->m_arr = new_arr;
				this->m_capacity = new_cap;
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
				for (size_type i = 0; i < this->m_size; ++i)
						this->m_alloc.destroy(&this->m_arr[i]);
				if (n > this->m_capacity)
				{
					this->m_alloc.deallocate(this->m_arr, this->m_capacity);
					this->m_capacity = n;
					this->m_arr = this->m_alloc.allocate(n);
				}
				for (size_type i = 0; i < n; ++i)
					this->m_alloc.construct(&this->m_arr[i], val);
				this->m_size = n;
			}

			template <class InputIterator>
			void assign (InputIterator first, InputIterator last,
						typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			{
				size_type new_size = 0;
				for (size_type i = 0; i < this->m_size; ++i)
					this->m_alloc.destroy(&this->m_arr[i]);
				for (InputIterator it = first; it != last; ++it)
					new_size += 1;
				if (new_size > max_size())
					reserve(new_size);
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
				if (this->m_size == this->m_capacity)
					(this->m_capacity == 0) ? reserve(2) : reserve(this->m_capacity * 2);
				this->m_alloc.construct(this->m_arr + this->m_size, value);
				m_size++;
			}

			void pop_back()
			{
				--this->m_size;
			}

			iterator insert (iterator position, const value_type& val)
			{
				size_type n = position - this->begin();
				if (this->m_size + 1 >= this->m_capacity)
				{
					this->m_capacity = this->m_capacity * 2 + (this->m_capacity == 0);
					if (this->m_capacity < m_size + 1)
						this->m_capacity = m_size + 1;
					pointer new_arr = this->m_alloc.allocate(this->m_capacity);
					int i = 0;
					for (iterator it = begin(); it != position; ++it, ++i)
						this->m_alloc.construct(new_arr + i, *it);
					this->m_alloc.construct(new_arr + i, val);
					i += 1;
					for (iterator it = position; it != end(); ++it, ++i)
						this->m_alloc.construct(new_arr + i, *it);
					for (size_type i = 0; i < this->m_size; ++i)
						this->m_alloc.destroy(&this->m_arr[i]);
					if (this->m_arr)
					this->m_alloc.deallocate(this->m_arr, this->m_capacity);
					this->m_arr = new_arr;
					this->m_size += 1;
				}
				else
				{
					iterator it = end();
					for (; it != position; --it)
					{
						this->m_alloc.destroy(&(*it) + 1);
						this->m_alloc.construct((&(*it) + 1), *it);
					}
					this->m_alloc.destroy(&(*it) + 1);
					this->m_alloc.construct((&(*it) + 1), *it);
					this->m_alloc.destroy(&(*position));
					this->m_alloc.construct(&(*position), val);
					this->m_size += 1;
				}
				return (iterator(this->begin() + n));
			}

			void insert (iterator position, size_type n, const value_type& val)
			{
				if (this->m_size + n >= this->m_capacity)
				{
					this->m_capacity = this->m_capacity * 2 + (this->m_capacity == 0);
					if (this->m_capacity < this->m_size + n)
						this->m_capacity = this->m_size + n;
					pointer new_arr = this->m_alloc.allocate(this->m_capacity);
					int i = 0;
					for (iterator it = begin(); it != position; ++it, ++i)
						this->m_alloc.construct(new_arr + i, *it);
					for (size_type j = 0; j < n; ++j, ++i)
						this->m_alloc.construct(new_arr + i, val);
					for (iterator it = position; it != end(); ++it, ++i)
						this->m_alloc.construct(new_arr + i, *it);
					for (size_type i = 0; i < this->m_size; ++i)
						this->m_alloc.destroy(&this->m_arr[i]);
					if (this->m_arr)
						this->m_alloc.deallocate(this->m_arr, this->m_capacity);
					this->m_size += n;
					this->m_arr = new_arr;
				}
				else
				{
					iterator it = end();
					for (; it != position; --it)
					{
						this->m_alloc.destroy(&(*it) + n);
						this->m_alloc.construct((&(*it) + n), *it);
					}
					this->m_alloc.destroy(&(*it) + n);
					this->m_alloc.construct((&(*it) + n), *it);
					for (size_type j = 0; j != n; ++j, ++it)
					{
						this->m_alloc.destroy(&(*it));
						this->m_alloc.construct(&(*it), val);
					}
					this->m_size += n;
				}
			}

			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,
						typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			{
				
				size_type n = 0;
				size_type new_cap = this->m_capacity;
				size_type	start = position - this->begin();
				for (InputIterator it = first; it != last; ++it)
					n++;
				if (this->m_size + n >= this->m_capacity)
				{
					new_cap = new_cap * 2 + (new_cap == 0);
					if (new_cap < this->m_size + n)
						new_cap = this->m_size + n;
					pointer new_arr = this->m_alloc.allocate(new_cap);
					// for (iterator it = begin(); it != position; ++it, ++i)
					// 	this->m_alloc.construct(new_arr + i, *it);
					// InputIterator jt = first;
					// for (size_type j = 0; j < n; ++j, ++i, ++jt)
					// 	this->m_alloc.construct(new_arr + i, *jt);
					// for (iterator it = position; it != end(); ++it, ++i)
					// 	this->m_alloc.construct(new_arr + i, *it);
					try
					{
						std::uninitialized_copy(begin(), position, new_arr);
						std::uninitialized_copy(first, last, new_arr + start);
						std::uninitialized_copy(position, end(), new_arr + start + n);
					}
					catch(...)
					{
						this->m_alloc.deallocate(new_arr,new_cap);
						throw;
					}
					for (size_type i = 0; i < this->m_size; ++i)
						this->m_alloc.destroy(&this->m_arr[i]);
					if (this->m_arr)
						this->m_alloc.deallocate(this->m_arr, this->m_capacity);
					this->m_size += n;
					this->m_arr = new_arr;
					this->m_capacity = new_cap;
				}
				else
				{
					iterator it = end();
					for (; it != position; --it)
					{
						this->m_alloc.destroy(&(*it) + n);
						this->m_alloc.construct((&(*it) + n), *it);
					}
					this->m_alloc.destroy(&(*it) + n);
					this->m_alloc.construct((&(*it) + n), *it);
					InputIterator jt = first;
					for (size_type j = 0; j != n; ++j, ++it, ++jt)
					{
						this->m_alloc.destroy(&(*it));
						this->m_alloc.construct(&(*it), *jt);
					}
					this->m_size += n;
				}
			}

			iterator erase (iterator position)
			{
				pointer p = &(*position);
				this->m_alloc.destroy(&(*p));
				for (size_type i = 0; i < this->m_size; ++i)
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
					sum++;
				}
				this->m_size -= sum;
				for (size_type i = 0; i < this->m_size; ++i)
					this->m_alloc.construct(&(*first) + i, *(&(*last) + i));
				return (iterator(p));
			}

			void swap (vector& x)
			{
				pointer				m_arr_new = this->m_arr;
				size_type			m_size_new = this->m_size;
				size_type			m_capacity_new = this->m_capacity;

				this->m_arr = x.m_arr;
				this->m_size = x.m_size;
				this->m_capacity = x.m_capacity;

				x.m_arr = m_arr_new;
				x.m_size = m_size_new;
				x.m_capacity = m_capacity_new;
			}

			void clear()
			{
				for (size_type i = 0; i < this->m_size; ++i)
					this->m_alloc.destroy(&this->m_arr[i]);
				this->m_size = 0;
			}

			allocator_type get_allocator() const
			{
				return (this->m_alloc);
			}

			value_type* data()
			{
				return (this->m_arr);
			}

			const value_type* data() const
			{
				return (this->m_arr);
			}
	};

	template<class T, class Alloc>
	bool operator==(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		if (lhs.size() == rhs.size())
		{
			typename ft::vector<T>::const_iterator it1 = lhs.begin();
			typename ft::vector<T>::const_iterator it2 = rhs.begin();
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