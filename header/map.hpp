#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "UtilsIterator/iterator.hpp"
#include "UtilsIterator/bidirectional_iterator.hpp"

namespace ft
{
	template <class Key, class T,
	class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map
	{
		public:
			typedef Key													key_type;
			typedef T													mapped_type;
			typedef pair<const key_type, mapped_type>					value_type;
			typedef Compare												key_compare;
			//value_compare;
			typedef Alloc												allocator_type;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;
			typedef bidirectional_iterator<true, value_type>			const_iterator;
			typedef bidirectional_iterator<false, value_type>			iterator;
			typedef ft::reverse_iterator<iterator>						reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
			typedef ft::iterator_traits<iterator>::difference_type		difference_type;
			typedef size_t												size_type;
	};
}
#endif