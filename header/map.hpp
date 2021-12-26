#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "iterator.hpp"
#include "bidirectional_iterator.hpp"
#include "RedBlackTree.hpp"

namespace ft
{
	template <class Key, class T,
	class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map
	{
		public:
			typedef Key															key_type;
			typedef T															mapped_type;
			typedef pair<const key_type, mapped_type>							value_type;
			typedef Compare														key_compare;
			typedef Alloc														allocator_type;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef bidirectional_iterator<true, value_type>					const_iterator;
			typedef bidirectional_iterator<false, value_type>					iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;
			typedef size_t														size_type;

			class value_compare : std::binary_function<value_type, value_type, bool>
			{
				friend class map<key_type, mapped_type, key_compare, Alloc>;

				protected:
					Compare comp;
					value_compare(Compare c) : comp(c) {}

				public:
					bool operator()(const value_type &x, const value_type &y) const
					{
						return (comp(x.first, y.first));
					}
			};
		private:
			typedef typename allocator_type::template rebind<Node<value_type> >::other	node_allocator;
			typedef RedBlackTree<value_type, value_compare, node_allocator>				node_container;
			typedef Node<value_type>*													node_pointer;
			typedef Node<value_type>&													node_reference;
			
			node_container	m_container;
			key_compare		m_compare;
			allocator_type	m_alloc;
			
		public:
			explicit map(const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type()) : m_container(node_container(value_compare(comp))),
																		m_compare(comp),
																		m_alloc(alloc)
			{
			}
			
			template <class InputIterator>
			map(InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) : m_container(node_container(value_compare(comp))),
																m_compare(comp),
																m_alloc(alloc)
			{
				insert(first, last);
			}

			map(const map& x) : m_container(x.m_container), m_compare(x.m_compare), m_alloc(x.m_alloc)
			{
			}

			~map()
			{
				clear();
			}

			map& operator=(const map& x)
			{
				if (this != &x)
				{
					clear();
					m_container = x.m_container;
				}
				return (*this);
			}

			iterator begin()
			{
				return (iterator(m_container.get_node_ptr(), m_container.get_root()));
			}

			const_iterator begin() const
			{
				return (const_iterator(m_container.get_node_ptr(), m_container.get_root()));
			}

			iterator end()
			{
				return (iterator(NULL, m_container.get_root()));
			}

			const_iterator end() const
			{
				return (const_iterator(NULL, m_container.get_root()));
			}

			reverse_iterator rbegin()
			{
				return (reverse_iterator(end()));
			}

			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(end()));
			}

			reverse_iterator rend()
			{
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(begin()));
			}

			bool empty() const
			{
				if (!m_container.get_size())
					return (true);
				else
					return (false);
			}

			size_type size() const
			{
				return (m_container.get_size());
			}

			size_type max_size() const
			{
				return (m_container.get_alloc().max_size());
			}

			mapped_type& at(const key_type& k)
			{
				ft::pair< const key_type, mapped_type> value = ft::make_pair<const key_type, mapped_type>(k, mapped_type());
				node_pointer tmp = m_container.search_node(value);
				if (!tmp)
					throw std::out_of_range("map");
				return (tmp->value.second);
			}

			const mapped_type& at(const key_type& k) const
			{
				ft::pair< const key_type, mapped_type> value = ft::make_pair<const key_type, mapped_type>(k, mapped_type());
				node_pointer tmp = m_container.search_node(value);
				if (!tmp)
					throw std::out_of_range("map");
				return (tmp->value.second);
			}

			mapped_type& operator[](const key_type& k)
			{
				ft::pair< const key_type, mapped_type> value = ft::make_pair<const key_type, mapped_type>(k, mapped_type());
				return insert(value).first->second;
			}

			pair<iterator,bool> insert(const value_type& val)
			{
				bool b_insert;
				node_pointer tmp = m_container.insert(val, &b_insert);
				return (ft::make_pair<iterator, bool>(iterator(tmp, m_container.get_root()), b_insert));
			}

			iterator insert(iterator position, const value_type& val)
			{
				return iterator(m_container.insert(position.base(), val), m_container.get_root());
			}

			template <class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					insert(*first);
					++first;
				}
			}

			void erase(iterator position)
			{
				m_container.erase(position.base());
			}

			size_type erase(const key_type& k)
			{
				ft::pair<const key_type, mapped_type> value = ft::make_pair<const key_type, mapped_type>(k, mapped_type());
				return (m_container.erase(value));
			}

			void erase(iterator first, iterator last)
			{
				for(iterator it; first != last;)
				{
					it = first++;
					erase(it);
				}
			}

			void swap(map& x)
			{
				m_container.swap(x.m_container);
			}

			void clear()
			{
				m_container.clear();
			}

			key_compare key_comp() const
			{
				return (this->m_compare);
			}

			value_compare value_comp() const
			{
				return (value_compare(key_compare()));
			}

			iterator find (const key_type& k)
			{
				ft::pair<const key_type, mapped_type> value = ft::make_pair<const key_type, mapped_type>(k, mapped_type());
				return (iterator(m_container.search_node(value), m_container.get_root()));
			}

			const_iterator find (const key_type& k) const
			{
				ft::pair<const key_type, mapped_type> value = ft::make_pair<const key_type, mapped_type>(k, mapped_type());
				return (const_iterator(m_container.search_node(value), m_container.get_root()));
			}

			size_type count (const key_type& k) const
			{
				ft::pair<const key_type, mapped_type> value = ft::make_pair<const key_type, mapped_type>(k, mapped_type());
				if (m_container.search_node(value))
					return (1);
				else
					return (0);
			}

			iterator lower_bound (const key_type& k)
			{
				ft::pair<const key_type, mapped_type> value = ft::make_pair<const key_type, mapped_type>(k, mapped_type());
				node_pointer other = NULL;
				m_container.lower(value, m_container.get_root(), &other);
				return (iterator(other, m_container.get_root()));
			}

			const_iterator lower_bound(const key_type& k) const
			{
				ft::pair<const key_type, mapped_type> value = ft::make_pair<const key_type, mapped_type>(k, mapped_type());
				node_pointer other = NULL;
				m_container.lower(value, m_container.get_root(), &other);
				return (const_iterator(other, m_container.get_root()));
			}

			iterator upper_bound(const key_type& k)
			{
				node_pointer sougth = NULL;
				ft::pair<const key_type, mapped_type> p = ft::make_pair<const key_type, mapped_type>(k, mapped_type());
				m_container.upper(p, m_container.get_root(), &sougth);
				return iterator(sougth, m_container.get_root());
			}

			const_iterator upper_bound(const key_type& k) const
			{
				ft::pair<const key_type, mapped_type> value = ft::make_pair<const key_type, mapped_type>(k, mapped_type());
				node_pointer other = NULL;
				m_container.upper(value, m_container.get_root(), &other);
				return (const_iterator(other, m_container.get_root()));
			}

			pair<const_iterator,const_iterator> equal_range(const key_type& k) const
			{
				return ft::make_pair(lower_bound(k), upper_bound(k));
			}

			pair<iterator,iterator> equal_range(const key_type& k)
			{
				return ft::make_pair(lower_bound(k), upper_bound(k));
			}

			allocator_type get_allocator() const
			{
				return (this->m_alloc);
			}
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(rhs < lhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs < rhs));
	}

	template<class Key, class T, class Compare, class Alloc>
	void swap(map<Key,T,Compare,Alloc>& lhs, map<Key,T,Compare,Alloc>& rhs)
	{
		lhs.swap(rhs);
	}
}
#endif