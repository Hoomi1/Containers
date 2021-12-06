#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include <iostream>

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

			bool operator>(const random_access_iterator &other) const
			{
				return (this->m_Ptr > other.m_Ptr);
			}

			bool operator<(const random_access_iterator &other) const
			{
				return (this->m_Ptr < other.m_Ptr);
			}

			bool operator>=(const random_access_iterator &other) const
			{
				return (this->m_Ptr >= other.m_Ptr);
			}

			bool operator<=(const random_access_iterator &other) const
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
				return (*(this->m_Ptr + pos));
			}	

			operator random_access_iterator<const T>() const
			{
				return (random_access_iterator<const T>(this->m_Ptr));
			}

			template <typename U>
			friend typename ft::random_access_iterator<U>::difference_type operator-(const ft::random_access_iterator<U> lhs,
																					const ft::random_access_iterator<U> rhs);

			template<typename U_L, typename U_R>
			friend typename ft::random_access_iterator<U_L>::difference_type operator-(const ft::random_access_iterator<U_L> lhs,
																					const ft::random_access_iterator<U_R> rhs);

			template <typename U>
			friend bool operator==(const ft::random_access_iterator<U> lhs, const ft::random_access_iterator<U> rhs);

			template<typename U_L, typename U_R>
			friend bool operator==(const ft::random_access_iterator<U_L> lhs, const ft::random_access_iterator<U_R> rhs);

			template <typename U>
			friend bool operator!=(const ft::random_access_iterator<U> lhs, const ft::random_access_iterator<U> rhs);

			template<typename U_L, typename U_R>
			friend bool operator!=(const ft::random_access_iterator<U_L> lhs, const ft::random_access_iterator<U_R> rhs);

			template <typename U>
			friend bool operator<(const ft::random_access_iterator<U> lhs, const ft::random_access_iterator<U> rhs);

			template<typename U_L, typename U_R>
			friend bool operator<(const ft::random_access_iterator<U_L> lhs, const ft::random_access_iterator<U_R> rhs);

			template <typename U>
			friend bool operator>(const ft::random_access_iterator<U> lhs, const ft::random_access_iterator<U> rhs);

			template<typename U_L, typename U_R>
			friend bool operator>(const ft::random_access_iterator<U_L> lhs, const ft::random_access_iterator<U_R> rhs);

			template <typename U>
			friend bool operator<=(const ft::random_access_iterator<U> lhs, const ft::random_access_iterator<U> rhs);

			template<typename U_L, typename U_R>
			friend bool operator<=(const ft::random_access_iterator<U_L> lhs, const ft::random_access_iterator<U_R> rhs);

			template <typename U>
			friend bool operator>=(const ft::random_access_iterator<U> lhs, const ft::random_access_iterator<U> rhs);

			template<typename U_L, typename U_R>
			friend bool operator>=(const ft::random_access_iterator<U_L> lhs, const ft::random_access_iterator<U_R> rhs);
	};

	template <typename T>
	ft::random_access_iterator<T> operator+(typename ft::random_access_iterator<T>::difference_type _num,
											ft::random_access_iterator<T> it)
	{
		ft::random_access_iterator<T> temp(it);
		temp += _num;
		return (temp);
	}

	template <typename T>
	ft::random_access_iterator<T> operator-(typename ft::random_access_iterator<T>::difference_type _num,
											ft::random_access_iterator<T> it)
	{
		const ft::random_access_iterator<T> temp(it);
		temp -= _num;
		return (temp);
	}

	template <typename T>
	typename ft::random_access_iterator<T>::difference_type operator-(const ft::random_access_iterator<T> lhs,
																	const ft::random_access_iterator<T> rhs)
	{
		return (lhs.m_Ptr - rhs.m_Ptr);
	}

	template<typename T_L, typename T_R>
	typename ft::random_access_iterator<T_L>::difference_type operator-(const ft::random_access_iterator<T_L> lhs,
																	const ft::random_access_iterator<T_R> rhs)
	{
		return (lhs.m_Ptr - rhs.m_Ptr);
	}

	template <typename T>
	bool operator==(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
	{
		return (lhs.m_Ptr == rhs.m_Ptr);
	}

	template<typename T_L, typename T_R>
	bool operator==(const ft::random_access_iterator<T_L> lhs, const ft::random_access_iterator<T_R> rhs)
	{
		return (lhs.m_Ptr == rhs.m_Ptr);
	}


	template <typename T>
	bool operator!=(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
	{
		return (lhs.m_Ptr != rhs.m_Ptr);
	}

	template<typename T_L, typename T_R>
	bool operator!=(const ft::random_access_iterator<T_L> lhs, const ft::random_access_iterator<T_R> rhs)
	{
		return (lhs.m_Ptr != rhs.m_Ptr);
	}

	template <typename T>
	bool operator<(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
	{
		return (lhs.m_Ptr < rhs.m_Ptr);
	}

	template<typename T_L, typename T_R>
	bool operator<(const ft::random_access_iterator<T_L> lhs, const ft::random_access_iterator<T_R> rhs)
	{
		return (lhs.m_Ptr < rhs.m_Ptr);
	}

	template <typename T>
	bool operator>(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
	{
		return (lhs.m_Ptr > rhs.m_Ptr);
	}

	template<typename T_L, typename T_R>
	bool operator>(const ft::random_access_iterator<T_L> lhs, const ft::random_access_iterator<T_R> rhs)
	{
		return (lhs.m_Ptr > rhs.m_Ptr);
	}

	template <typename T>
	bool operator<=(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
	{
		return (lhs.m_Ptr <= rhs.m_Ptr);
	}

	template<typename T_L, typename T_R>
	bool operator<=(const ft::random_access_iterator<T_L> lhs, const ft::random_access_iterator<T_R> rhs)
	{
		return (lhs.m_Ptr <= rhs.m_Ptr);
	}

	template <typename T>
	bool operator>=(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
	{
		return (lhs.m_Ptr >= rhs.m_Ptr);
	}

	template<typename T_L, typename T_R>
	bool operator>=(const ft::random_access_iterator<T_L> lhs, const ft::random_access_iterator<T_R> rhs)
	{
		return (lhs.m_Ptr >= rhs.m_Ptr);
	}
}

#endif