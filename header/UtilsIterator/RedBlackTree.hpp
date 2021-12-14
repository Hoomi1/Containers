#ifndef REDBLACKTREE
#define REDBLACKTREE

#include "iterator.hpp"
#include "bidirectional_iterator.hpp"

namespace ft
{
	template <typename T, class Compare, class Alloc>
	class RedBlackTree
	{
		public:
			typedef T				value_type;
			typedef Compare			compare_key;
			typedef size_t			size_type;
			typedef Alloc			allocator_type;
			typedef ft::Node<T>*	pointer;
			typedef ft::Node<T>&	reference;

		private:
			compare_key		m_compare;
			allocator_type	m_alloc;
			pointer			_root;
			pointer			_node_ptr;
			size_type		m_size;
			
			void clearTree(ft::Node<T> node)
			{
				
			}
		public:

			RedBlackTree(const compare_key cmp) : m_compare(cmp), m_alloc(allocator_type()), _root(NULL), _node_ptr(NULL), m_size(0) {}

			RedBlackTree(const RedBlackTree &other)
			{
				this->m_alloc = other.m_alloc;
				this->m_compare = other.m_compare;
				this->m_size = other.m_size;
				this->_node_ptr = NULL;
				this->_root = NULL;
			}

			~RedBlackTree()
			{

			}
	};
}
#endif