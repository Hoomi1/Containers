#ifndef REDBLACKTREE
#define REDBLACKTREE

#include "iterator.hpp"
#include "bidirectional_iterator.hpp"

namespace ft
{
	typedef enum
	{
		RED,
		BLACK
	} color;

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
			compare_key		_compare;
			allocator_type	_alloc;
			pointer			_root;
			pointer			_node_ptr;
			size_type		_size;

		public:
			RedBlackTree(const compare_key cmp) : _compare(cmp), _alloc(allocator_type()), _root(NULL), _node_ptr(NULL), _size(0) {}

			RedBlackTree(const RedBlackTree &other)
			{
				this->_alloc = other._alloc;
				this->_compare = other._compare;
				this->_size = other._size;
				this->_node_ptr = NULL;
				this->_root = NULL;
				copyTree(&this->_root, other._root);
				// if (!this->_node_ptr)
				// {
				// 	this->_node_ptr = this->_root;
				// 	if (this->_node_ptr)
				// 		minimum(this->_node_ptr);
				// 	return ;
				// }
				// if (this->_node_ptr->node_right)
				// {
				// 	this->_node_ptr = this->_node_ptr->node_right;
				// 	minimum(this->_node_ptr);
				// }
				// else
				// {
				// 	while (this->_node_ptr->node_parent && this->_node_ptr == this->_node_ptr->node_parent->right)
				// 		this->_node_ptr = this->_node_ptr->node_parent;
				// 	this->_node_ptr = this->_node_ptr->node_parent;
				// }
				left_minimum();
			}

			~RedBlackTree()
			{
				clearTree(this->_root);
			}

			RedBlackTree &operator=(const RedBlackTree &other)///////////////////////
			{
				if (this != &other)
				{
					clearTree(this->_root);
					copyTree(&this->_root, other._root);
					// if (!this->_node_ptr)
					// {
					// 	this->_node_ptr = this->_root;
					// 	if (this->_node_ptr)
					// 		minimum(this->_node_ptr);
					// 	return ;
					// }
					// if (this->_node_ptr->node_right)
					// {
					// 	this->_node_ptr = this->_node_ptr->node_right;
					// 	minimum(this->_node_ptr);
					// }
					// else
					// {
					// 	while (this->_node_ptr->node_parent && this->_node_ptr == this->_node_ptr->node_parent->right)
					// 		this->_node_ptr = this->_node_ptr->node_parent;
					// 	this->_node_ptr = this->_node_ptr->node_parent;
					// }
					left_minimum();
					this->_size = other._size;
				}
				return (*this);
			}

			void swap (RedBlackTree &other)
			{
				pointer new_node = this->_root;
				this->_root = other._root;
				other._root = new_node;
				pointer new_size = this->_size;
				this->_size = other._size;
				other._size = new_size;
				pointer new_node_ptr = this->_node_ptr;
				this->_node_ptr = other._node_ptr;
				other._node_ptr = new_node_ptr;
			}

			void erase(pointer position)
			{
				if (!position)
					return ;
				
				// if (position == this->_node_ptr)
				// {
				// 	if (!this->_node_ptr)
				// 	{
				// 		this->_node_ptr = this->_root;
				// 		if (this->_node_ptr)
				// 			minimum(this->_node_ptr);
				// 		return ;
				// 	}
				// 	if (this->_node_ptr->node_right)
				// 	{
				// 		this->_node_ptr = this->_node_ptr->node_right;
				// 		minimum(this->_node_ptr);
				// 	}
				// 	else
				// 	{
				// 		while (this->_node_ptr->node_parent && this->_node_ptr == this->_node_ptr->node_parent->right)
				// 			this->_node_ptr = this->_node_ptr->node_parent;
				// 		this->_node_ptr = this->_node_ptr->node_parent;
				// 	}
				// }
				left_minimum();
				delete_tree(position);
				--this->_size;
			}

			pointer search_node(const value_type &value) const
			{
				pointer search = this->_root;
				while (search)
				{
					if (this->_compare(value, search->value))
						search = search->node_left;
					else if (this->_compare(search->value, value))
						search = search->node_right;
					else
						break ;
				}
				return (search);
			}

			bool erase(const value_type &value)
			{
				pointer search = search_node(value);
				while (search)
				{
					if (this->_compare(value, search->value))
						search = search->node_left;
					else if (this->_compare(search->value, value))
						search = search->node_right;
					else
						break ;
				}

				if (!search)
					return (false);
				
				
				left_minimum();
				delete_tree(search);
				--this->_size;
				return (true);
			}
			////////////////
			pointer insert(pointer position, const value_type& val)
			{

			}

			pointer insert(const value_type& val)
			{

			}

			////////////////
			void clear()
			{
				clearTree(this->_root);
				this->_size = 0;
			}

		private:
			void copyTree(pointer *lnode, pointer rnode)///////////////??????????????
			{
				if (!rnode)
					return ;
				
				lnode = create_node(rnode->value);
				if (rnode->node_parent)
				{
					if (rnode->node_parent->node_right == rnode)
						(*lnode)->node_parent->node_right = *lnode;
					else
						(*lnode)->node_parent->node_left = *lnode;
				}
				copyTree(&((*lnode)->node_left), rnode->node_left);
				copyTree(&((*lnode)->node_right), rnode->node_right);
			}

			void left_minimum()
			{
				if (!this->_node_ptr)
				{
					this->_node_ptr = this->_root;
					if (this->_node_ptr)
						minimum(this->_node_ptr);
					return ;
				}
				if (this->_node_ptr->node_right)
				{
					this->_node_ptr = this->_node_ptr->node_right;
					minimum(this->_node_ptr);
				}
				else
				{
					while (this->_node_ptr->node_parent && this->_node_ptr == this->_node_ptr->node_parent->right)
						this->_node_ptr = this->_node_ptr->node_parent;
					this->_node_ptr = this->_node_ptr->node_parent;
				}
			}

			pointer minimum(pointer left_more)/////////////////////
			{
				while (left_more->node_left != NULL)
					left_more = left_more->node_left;
				return (left_more);
			}

			pointer get_grandparent(pointer x)
			{
				if (x->node_parent != NULL)
					return (x->node_parent->node_paren);
				return (NULL);
			}

			pointer get_uncle(pointer x)
			{
				pointer old = grandparent(x);
				if (old == NULL)
					return (NULL);
				if (x->node_parent == old->node_left)
					return (old->node_right);
				else
					return (old->node_left);
			}

			void rotateRight(pointer x)
			{
				pointer pivot = x->node_left;

				if (x == this->_root)
					this->_root = pivot;
				pivot->node_parent = x->node_parent;
				if (pivot->node_parent != NULL)
				{
					if (x->node_parent->node_left == x)
						x->node_parent->node_left = pivot;
					else
						x->node_parent->node_right = pivot;
				}
				x->node_left = pivot->node_right;
				if (x->node_left != NULL)
					pivot->node_right->node_parent = x;
				x->node_parent = pivot;
				pivot->node_right = x;
			}

			void rotateLeft(pointer x)
			{
				pointer pivot = x->node_right;

				if (x == this->_root)
					this->_root = pivot;
				pivot->node_parent = x->node_parent;
				if (pivot->node_parent != NULL)
				{
					if (x->node_parent->node_left == x)
						x->node_parent->node_left = pivot;
					else
						x->node_parent->node_right = pivot;
				}
				x->node_right = pivot->node_left;
				if (x->node_right != NULL)
					pivot->node_left->node_parent = x;
				x->node_parent = pivot;
				pivot->node_left = x;
			}

			void insert_case1(pointer x)
			{
				if (x->node_parent == NULL)
				{
					x->red = BLACK;
					this->_root = x;
				}
				else
					insert_case2(x);
			}

			void insert_case2(pointer x)
			{
				if (x->node_parent->red == BLACK) ///////
					return;
				else
					insert_case3(x);
			}

			void insert_case3(pointer x)
			{
				pointer new_uncle = get_uncle(x);

				if (new_uncle != NULL && new_uncle->red == RED)
				{
					x->node_parent->red = BLACK;
					new_uncle->red = BLACK;
					pointer old = get_grandparent(x);
					old->red = RED;
					insert_case1(old);
				}
				else
					insert_case4(x);
			}

			void insert_case4(pointer x)
			{
				pointer old = get_grandparent(x);

				if ((x == x->node_parent->node_right) && (x->node_parent == old->node_left))
				{
					rotateLeft(x->node_parent);
					x = x->node_left;
				}
				else if ((x == x->node_parent->node_left) && (x->node_parent == old->node_right))
				{
					rotateRight(x->node_parent);
					x = x->node_right;
				}
				insert_case5(x);
			}

			void insert_case5(pointer x)
			{
				pointer old = get_grandparent(x);

				x->node_parent->red = BLACK;
				old->red = RED;
				if ((x == x->node_parent->node_left) && (x->node_parent == old->node_left))
					rotateRight(old);
				else
					rotateLeft(old);
			}

			//pointer get_right_min(pointer x)
			//{
			//	x = x->node_right;
			//	if (x)
			//	{
			//		while (x->node_left)
			//			x = x->node_left;
			//	}
			//	return (x);
			//}

			/*pointer get_left_max(pointer x)
			{
				x = x->node_left;
				if (x)
				{
					while (x->node_right)
						x = x->node_right;
				}
				return (x);
			}*/

			pointer get_sibling(pointer x)
			{
				if (x == x->node_parent->node_left)
					return (x->node_parent->node_right);
				else
					return (x->node_parent->node_left);
			}

			pointer get_search_for_swap(pointer x)
			{
				x = x->node_left;
				if (x)
				{
					while (x->node_right)
						x = x->node_right;
				}
				else if (!x)
				{
					x = x->node_right;
					if (x)
					{
						while (x->node_left)
							x = x->node_left;
					}
				}
				return (x);
			}

			void swap_nodes(pointer before, const pointer after)
			{
				if (this->_root == before)
					this->_root == after;
				if (before->node_parent)
				{
					if (before->node_parent->node_left == before)
						before->node_parent->node_left = after;
					else
						before->node_parent->node_right = after;
				}
				if (after->node_parent->node_left == after)
					after->node_parent->node_left = before;
				else
					after->node_parent->node_right = before;
				
				pointer new_node = before->node_parent;
				before->node_parent = after->node_parent;
				after->node_parent = new_node;

				if (after->node_left)
					after->node_left->node_parent = before;
				if (before->node_left)
					before->node_left->node_parent = after;
				new_node = before->node_left;
				before->node_left = after->node_left;
				after->node_left = new_node;

				if (after->node_right)
					after->node_right->node_parent = before;
				if (before->node_right)
					before->node_right->node_parent = after;
				new_node = before->node_right;
				before->node_right = after->node_right;
				after->node_right = new_node;

				bool new_color = before->red;
				before->red = after->red;
				after->red = new_color;
			}

			void delete_case_rebalance(pointer x)
			{
				pointer s = get_sibling(x);

				if (!s)
					return ;

				if (x == x->node_parent->node_left)
				{
					if (s->red == BLACK)
					{
						if (s->node_right && s->node_right->red == RED)
						{
							delete_case_RL_red_child(s, x);
						}
						else if (s->node_left && s->node_left->red == RED)
						{
							bool color = s->node_left->red;
							s->node_left->red = s->node_right->red;
							s->node_right->red = color;
							rotateRight(s);
							delete_case_RL_red_child(s, x);
						}
						else if (s->node_left->red == BLACK && s->node_right->red == BLACK)
						{
							s->red = RED;
							if (x->node_parent->red == RED)
								x->node_parent->red = BLACK;
							else
								delete_case_rebalance(x->node_parent);
						}
					}
					else
					{
						s->node_parent->red = RED;
						s->red = BLACK;
						rotateLeft(s->node_parent);

						if (s->node_left->node_right)
						{
							s->node_left->node_right = RED:
							s->node_left = BLACK;
						}
						if (s != this->_root && s->red == BLACK)
							delete_case_rebalance(s);
					}
				}
				else
				{
					if (s->red == BLACK)
					{
						if (s->node_left && s->node_left->red == RED)
						{
							delete_case_RL_red_child(s, x)
						}
						else if (s->node_right && s->node_right->red == RED)
						{
							bool color = s->node_right->red;
							s->node_right->red = s->node_left->red;
							s->node_left->red = color;
							rotateLeft(s);
							delete_case_RL_red_child(s, x);
						}
						else if (s->node_left->red == BLACK && s->node_right->red == BLACK)
						{
							s->red = RED;
							if (x->node_parent->red == RED)
								x->node_parent->red = BLACK;
							else
								delete_case_rebalance(x->node_parent);
						}
					}
					else
					{
						s->node_parent->red = RED;
						s->red = BLACK;
						rotateLeft(s->node_parent);

						if (s->node_right->node_left)
						{
							s->node_right->node_left = RED:
							s->node_left = BLACK;
						}
						if (s != this->_root && s->red == BLACK)
							delete_case_rebalance(s);
					}
				}
			}

			void delete_case_RL_red_child(pointer s, pointer x)
			{
				if (x == x->node_parent->node_right)
				{
					s->red = x->node_parent->red;
					x->node_parent->red = BLACK;
					x->node_left->red = BLACK;
					rotateRight(x->node_parent);
				}
				if (x == x->node_parent->node_left)
				{
					s->red = x->node_parent->red;
					x->node_parent->red = BLACK;
					x->node_right->red = BLACK;
					rotateLeft(x->node_parent);
				}
			}

			void delete_tree(pointer x)
			{
				pointer child = get_search_for_swap(x);
				if (child)
				{
					swap_nodes(x, child);
					if (x->red == RED)
						delete_node(x);
					else if (x->node_left)
					{
						swap_nodes(x, x->node_left)
						delete_node(x);
					}
					else if (x->node_right)
					{
						swap_nodes(x, x->node_right)
						delete_node(x);
					}
					else
					{
						delete_case_rebalance(x);
						delete_node(x);
					}
				}
				else
				{
					if (x->red == BLACK)
					{
						if (x != this->_root)
						{	
							delete_case_rebalance(x);
							delete_node(x);
							return ;
						}
						delete_node(x);
					}
					if (x->red == RED)
						delete_node(x);
				}
			}

			void create_node(const value_type &value)
			{
				pointer new_node = this->_alloc.allocate(1);
				this->_alloc.construct(new_node, value);
				return (new_node);
			}

			void delete_node(pointer node)
			{
				if (node->node_parent)
				{
					if (node->node_parent->node_right == node)
						node->node_parent->node_right = NULL;
					else
						node->node_parent->node_left = NULL;
				}
				this->_alloc.destroy(node);
				this->_alloc.deallocate(node, 1);
				if (node == this->_root)
				{
					this->_root = NULL;
					this->_node_ptr = NULL;
				}
			}

			void clearTree(pointer node)
			{
				if (!node)
					return;
				clearTree(node->node_left);
				clearTree(node->node_right);
				delete_node(node);
			}
	};
}
#endif