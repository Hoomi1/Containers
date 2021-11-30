#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include <iterator>
namespace ft
{
	struct random_access_iterator_tag
	{
	};

	template <class Category, class T, class Distance = std::ptrdiff_t,
			class Pointer = T *, class Reference = T &>
	struct iterator //////////////////
	{
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};
	///////////////////// *iterator_traits* /////////////////////
	template <class Iterator>
	struct iterator_traits
	{
		typedef typename	Iterator::value_type value_type;
		typedef typename	Iterator::difference_type difference_type;
		typedef typename	Iterator::pointer pointer;
		typedef typename	Iterator::reference reference;
		typedef typename	Iterator::iterator_category iterator_category;
	};

	template <class T>
	struct iterator_traits<T *>
	{
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
		typedef ft::random_access_iterator_tag iterator_category;
	};

	template <class T>
	struct iterator_traits<const T *>
	{
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef const T *pointer;
		typedef const T &reference;
		typedef ft::random_access_iterator_tag iterator_category;
	};
	////////////////////////////////////////////////////////////
	//////////////////// *reverse_iterator* ////////////////////
	template <class Iter>
	class reverse_iterator : public ft::iterator<
								typename ft::iterator_traits<Iter>::iterator_category,
								typename ft::iterator_traits<Iter>::value_type,
								typename ft::iterator_traits<Iter>::difference_type,
								typename ft::iterator_traits<Iter>::pointer,
								typename ft::iterator_traits<Iter>::reference>
	{
	public:
		typedef Iter iterator_type;
		typedef typename ft::iterator_traits<Iter>::iterator_category iterator_category;
		typedef typename ft::iterator_traits<Iter>::value_type value_type;
		typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
		typedef typename ft::iterator_traits<Iter>::pointer pointer;
		typedef typename ft::iterator_traits<Iter>::reference reference;

	private:
		iterator_type itr;

	public:
		reverse_iterator() {}

		explicit reverse_iterator(iterator_type x) : itr(x) {}

		template <class Iterator>
		reverse_iterator(const reverse_iterator<Iterator> &other) : itr(other.base()) {}

		template <class iterator>
		reverse_iterator &operator=(const reverse_iterator<iterator> &other)
		{
			this->itr = other.base();
			return (*this);
		}

		~reverse_iterator(){};

		iterator_type base() const
		{
			return (this->itr);
		}

		reference operator*() const
		{
			iterator_type tmp = this->itr;
			return (*(--tmp));
		}

		pointer operator->() const
		{
			return (&(operator*()));
		}

		reference operator[](difference_type n) const
		{
			return (*(base() - n - 1));
		}

		reverse_iterator &operator++()
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

		reverse_iterator &operator--()
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
			return (reverse_iterator(this->itr - n));
		}

		reverse_iterator &operator+=(difference_type n)
		{
			this->itr += n;
			return (*this);
		}

		reverse_iterator operator-(difference_type n) const
		{
			return (reverse_iterator(this->itr + n));
		}

		reverse_iterator &operator-=(difference_type n)
		{
			this->itr -= n;
			return (*this);
		}
	};

	template <class Iterator1, class Iterator2>
	bool operator==(const reverse_iterator<Iterator1> &lhs,
					const reverse_iterator<Iterator2> &rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator!=(const reverse_iterator<Iterator1> &lhs,
					const reverse_iterator<Iterator2> &rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator<(const reverse_iterator<Iterator1> &lhs,
				const reverse_iterator<Iterator2> &rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator<=(const reverse_iterator<Iterator1> &lhs,
					const reverse_iterator<Iterator2> &rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator>(const reverse_iterator<Iterator1> &lhs,
				const reverse_iterator<Iterator2> &rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator>=(const reverse_iterator<Iterator1> &lhs,
					const reverse_iterator<Iterator2> &rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n,
										const reverse_iterator<Iterator>& rev_it)
	{
		return (rev_it + n );
	}

	template< class Iterator >
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs,
																const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() - rhs.base());
	}
	////////////////////////////////////////////////////////////
	/////////////////////// *enable_if* ///////////////////////
	template <bool B, class T = void>
	struct enable_if
	{
	};

	template <class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};
	////////////////////////////////////////////////////////////
	////////////////////////// *pair* //////////////////////////
	template <class T1, class T2>
	struct pair
	{
	public:
		typedef T1 first_type;
		typedef T2 second_type;

	public:
		first_type first;
		second_type second;

	public:
		pair() : first(), second() {}

		pair(const T1 &x, const T2 &y) : first(x), second(y) {}

		template <class U1, class U2>
		pair(const pair<U1, U2> &p) : first(p.first), second(p.second) {}

		~pair() {}

		pair &operator=(const pair &other)
		{
			if (this != &other)
			{
				this->first = other.first;
				this->second = other.second;
			}
			return (*this);
		}

		template <class U1, class U2>
		pair &operator=(const pair<U1, U2> &other)
		{
			if (this != &other)
			{
				this->first = other.first;
				this->second = other.second;
			}
			return (*this);
		}
	};

	template <class T1, class T2>
	ft::pair<T1, T2> make_pair(T1 t, T2 u)
	{
		return (ft::pair<T1, T2>(t, u));
	}

	template <class T1, class T2>
	bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		if (lhs.first == rhs.first && lhs.second == rhs.second)
			return (true);
		else
			return (false);
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T1, class T2>
	bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		if (lhs.first < rhs.first)
			return (true);
		else if (rhs.first < lhs.first)
			return (false);
		else if (lhs.second < rhs.second)
			return (true);
		else
			return (false);
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T1, class T2>
	bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (!(lhs < rhs));
	}
	////////////////////////////////////////////////////////////
	////////////////////// *is_integral* //////////////////////
	template <class T, T _value>
	struct integral_constant
	{
		typedef T value_type;
		static const T value = _value;
	};

	typedef ft::integral_constant<bool,true> true_type;
	typedef ft::integral_constant<bool,false> false_type;

	template <typename>
	struct is_type : public false_type {};
	template <>
	struct is_type<char> : public true_type {};
	template <>
	struct is_type<wchar_t> : public true_type {};
	template <>
	struct is_type<signed char> : public true_type {};
	template <>
	struct is_type<short int> : public true_type {};
	template <>
	struct is_type<int> : public true_type {};
	template <>
	struct is_type<long int> : public true_type {};
	template <>
	struct is_type<long long int> : public true_type {};
	template <>
	struct is_type<unsigned char> : public true_type {};
	template <>
	struct is_type<unsigned short int> : public true_type {};
	template <>
	struct is_type<unsigned int> : public true_type {};
	template <>
	struct is_type<unsigned long int> : public true_type {};
	template <>
	struct is_type<unsigned long long int> : public true_type {};

	template <class T>
	struct is_integral : public is_type<T>
	{
	};
	///////////////////////////////////////////////////////////
	//////////////// *lexicographical_compare* ////////////////
	template <class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
								InputIt2 first2, InputIt2 last2)
	{
		for (; (first1 != last1) && (first2 != last2); ++first1, (void)++first2)
		{
			if (*first1 < *first2)
				return (true);
			if (*first2 < *first1)
				return (false);
		}
		return ((first1 == last1) && (first2 != last2));
	}

	template <class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
								InputIt2 first2, InputIt2 last2,
								Compare comp)
	{
		for (; (first1 != last1) && (first2 != last2); ++first1, (void)++first2)
		{
			if (comp(*first1, *first2))
				return (true);
			if (comp(*first2, *first1))
				return (false);
		}
		return (first1 == last1) && (first2 != last2);
	}
	///////////////////////////////////////////////////////////
}
#endif