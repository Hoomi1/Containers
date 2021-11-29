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
			container_type container;

		public:
			explicit stack(const container_type& ctnr = container_type()) : container(ctnr) {}

			~stack() {}

			stack(const stack &other)
			{
				*this = other;
			}

			stack &operator=(const stack &other)
			{
				if (this != &other)
					this->container = other.container;
			}

			bool empty() const
			{
				return (this->container.empty());
			}

			size_type size() const
			{
				return (this->container.size());
			}

			value_type& top()
			{
				return (this->container.back());
			}

			const value_type& top() const
			{
				return (this->container.back());
			}

			void push (const value_type& val)
			{
				return (this->container.push_back());
			}

			void pop()
			{
				return (this->container.pop_back());
			}


	};

	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.container == rhs.container);
	}

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.container != rhs.container);
	}

	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.container < rhs.container);
	}

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.container <= rhs.container);
	}

	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.container > rhs.container);
	}

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.container >= rhs.container);
	}
}
#endif