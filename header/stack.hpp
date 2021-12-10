#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <iterator>
#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;
		
		protected:
			container_type c;

		public:
			explicit stack(const container_type& ctnr = container_type()) : c(ctnr) {}

			~stack() {}

			stack(const stack &other)
			{
				*this = other;
			}

			stack &operator=(const stack &other)
			{
				if (this != &other)
					this->c = other.c;
			}

			bool empty() const
			{
				return (this->c.empty());
			}

			size_type size() const
			{
				return (this->c.size());
			}

			value_type& top()
			{
				return (this->c.back());
			}

			const value_type& top() const
			{
				return (this->c.back());
			}

			void push (const value_type& val)
			{
				return (this->c.push_back(val));
			}

			void pop()
			{
				return (this->c.pop_back());
			}

			template <class U1, class U2>
			friend bool operator== (const stack<U1,U2>& lhs, const stack<U1,U2>& rhs);

			template <class U1, class U2>
			friend bool operator!= (const stack<U1,U2>& lhs, const stack<U1,U2>& rhs);

			template <class U1, class U2>
			friend bool operator< (const stack<U1,U2>& lhs, const stack<U1,U2>& rhs);

			template <class U1, class U2>
			friend bool operator<= (const stack<U1,U2>& lhs, const stack<U1,U2>& rhs);

			template <class U1, class U2>
			friend bool operator> (const stack<U1,U2>& lhs, const stack<U1,U2>& rhs);

			template <class U1, class U2>
			friend bool operator>= (const stack<U1,U2>& lhs, const stack<U1,U2>& rhs);
	};

	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c == rhs.c);
	}

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c != rhs.c);
	}

	template <class T, class Container>
	bool operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c < rhs.c);
	}

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c <= rhs.c);
	}

	template <class T, class Container>
	bool operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c > rhs.c);
	}

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c >= rhs.c);
	}
}
#endif