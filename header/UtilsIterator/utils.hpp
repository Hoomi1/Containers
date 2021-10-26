#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
//#include <iterator>
namespace ft
{
	struct random_access_iterator_tag
	{

	};
	///////////////////// *iterator_traits* /////////////////////
	template<class Iter>
	struct iterator_traits
	{
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iter::iterator_category	iterator_category;
	};

	template<class T>
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t					difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef ft::random_access_iterator_tag	iterator_category;
	};

	template<class T>
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t					difference_type;
		typedef T								value_type;
		typedef const T*						pointer;
		typedef const T&						reference;
		typedef ft::random_access_iterator_tag	iterator_category;
	};
	////////////////////////////////////////////////////////////
	//////////////////// *reverse_iterator* ////////////////////
	template<class Iter>
	class reverse_iterator
	{
		public:
			typedef Iter													iterator_type;
			typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iter>::value_type			value_type;
			typedef typename ft::iterator_traits<Iter>::difference_type	difference_type;
			typedef typename ft::iterator_traits<Iter>::pointer			pointer;
			typedef typename ft::iterator_traits<Iter>::reference			reference;
		protected:
			iterator_type	itr;
		public:
			reverse_iterator() : itr() {}

			explicit reverse_iterator(iterator_type x) : itr(x) {}

			template<class Iter>
			reverse_iterator(const reverse_iterator<Iter>& other) : itr(other.itr){}

			template<class Iter>
			reverse_iterator& operator=(const reverse_iterator<Iter>& other)
			{
				this->itr = other.base();
				return (*this);
			}

			~reverse_iterator() {};

			iterator_type base() const
			{
				return (this->itr);
			}

			reference operator*() const
			{
				iterator_type tmp = base();
				return (*(--tmp));
			}

			pointer operator->() const
			{
				return (&(operator*()));
			}

			reference operator[]( difference_type n ) const
			{
				return (*(base() - n - 1));
			}

			reverse_iterator& operator++()
			{
				--this->itr;
				return (*this);
			}

			reverse_iterator operator++(int)
			{
				iterator_type tmp = base();
				--this->tmp;
				return (*this);
			}

			reverse_iterator& operator--()
			{
				++this->itr;
				return (*this);
			}

			reverse_iterator operator--(int)
			{
				iterator_type tmp = base();
				++this->tmp;
				return (*this);
			}

			reverse_iterator operator+(difference_type n) const
			{
				return (base() - n);
			}

			reverse_iterator& operator+=(difference_type n)
			{
				this->itr += n;
				return (*this);
			}

			reverse_iterator operator-(difference_type n) const
			{
				return (base() + n);
			}

			reverse_iterator& operator-=(difference_type n)
			{
				this->itr -= n;
				return (*this);
			}
	};

	template< class Iterator1, class Iterator2 >
	bool operator==(const reverse_iterator<Iterator1>& lhs,
					const reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template< class Iterator1, class Iterator2 >
	bool operator!=(const reverse_iterator<Iterator1>& lhs,
					const reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template< class Iterator1, class Iterator2 >
	bool operator<(const reverse_iterator<Iterator1>& lhs,
					const reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template< class Iterator1, class Iterator2 >
	bool operator<=(const reverse_iterator<Iterator1>& lhs,
					const reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template< class Iterator1, class Iterator2 >
	bool operator>(const reverse_iterator<Iterator1>& lhs,
					const reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template< class Iterator1, class Iterator2 >
	bool operator>=(const reverse_iterator<Iterator1>& lhs,
					const reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}
	////////////////////////////////////////////////////////////
	/////////////////////// *enable_if* ///////////////////////
	template<class T1, class T2>
	struct pair
	{
		public:
			typedef T1	first_type;
			typedef T2	second_type;
		protected:
			first_type	first;
			second_type	second;
		public:
			pair() : first(), second() {}

			pair(const T1& x, const T2& y) : first(x), second(y) {}

			template< class U1, class U2 >
			pair(const pair<U1, U2>& p) : first(p.first), second(p.second) {}
			
			~pair() {}

			pair& operator=( const pair& other )
			{
				if (this != &other)
				{
					this->first = other.first;
					this->second = other.second;
				}
				return (*this);
			}

			template< class U1, class U2 >
			pair& operator=( const pair<U1,U2>& other )
			{
				if (this != &other)
				{
					this->first = other.first;
					this->second = other.second;
				}
				return (*this);
			}
	};

	template< class T1, class T2 >
	std::pair<T1,T2> make_pair(T1 t, T2 u)
	{

	}
	////////////////////////////////////////////////////////////
}
#endif