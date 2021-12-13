#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

namespace ft
{

	template <bool B, class T, class U>
	struct enable_because
	{
		typedef U type;
	};

	template <class T, class U>
	struct enable_because<true, T, U>
	{
		typedef T type;
	};

	///////////////////////////////////////////////////////////////////////////////
	template<class Data>
	struct Node
	{
		private:
			Node();
		
		public:
			Node	*node_parent;
			Node	*node_left;
			Node	*node_right;
			bool	red;
			Data	value;

		~Node()
		{
		}

		Node(const Node &n) : node_parent(n.node_parent),
								node_left(n.node_left),
								node_right(n.node_right),
								red(n.red)
								value(n.value){}
		
		Node(const Node *n, const Data &rvalue) : node_parent(n),
												node_left(NULL),
												node_right(NULL),
												red(0),
												value(rvalue) {}

		Node &operator=(const Node &other)
		{
			if (this != other)
			{
				this->red = other.red;
				this->node_left = other.node_left;
				this->node_parent = other.node_parent;
				this->node_right = other.node_right;
				this->value = other.value;
			}
			return (*this);
		}
	};

///////////////////////////////////////////////////////////////////////////////

	template <class Compare, typename T>
	class bidirectional_iterator
	{
		public:
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
			// typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer			pointer;
			// typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference			reference;
			typedef typename ft::enable_because<Compare, const T *, T *>::type					pointer;
			typedef typename ft::enable_because<Compare, const T &, T &>::type					reference;

		private:
			Node<value_type> *node_ptr;
			Node<value_type> *root;

			Node min(Node *x)
			{
				if (x->node_right == NULL)
					return (x);
				return (min(x->node_left));
			}

			Node max(Node *x)
			{
				if (x->node_right == NULL)
					return (x);
				return (max(x->node_right));
			}

			Node setnext()
			{
				if (node_ptr->node_right != NULL)
					return (min(node_ptr->node_right));
				Node<value_type> *new_node = node_ptr->node_parent;
				while (new_node != NULL && node_ptr == new_node->node_right)
				{
					node_ptr = new_node;
					new_node = new_node->node_parent;
				}
				return (new_node);
			}

			Node setprev()
			{
				if (node_ptr->node_left != NULL)
					return (max(node_ptr->node_parent));
				Node<value_type> *new_node = node_ptr->node_parent;
				while (new_node != NULL && node_ptr == new_node->node_left)
				{
					node_ptr = new_node;
					new_node = new_node->node_parent;
				}
				return (new_node);
			}

		public:
			bidirectional_iterator() {}

			bidirectional_iterator(const bidirectional_iterator &other) : node_ptr(other.node_ptr), root(other.root)
			{
			}

			bidirectional_iterator(Node *node_ptr, Node *root)
			{
				this->node_ptr = node_ptr;
				this->root = root;
			}

			virtual ~bidirectional_iterator() {}

			bidirectional_iterator	&operator=(const bidirectional_iterator &other)
			{
				if (this != &other)
				{
					this->node_ptr = other.node_ptr;
					this->root = root;
				}
				return (*other);
			}

			reference				operator*() const
			{
				return (this->node_ptr->value);
			}

			pointer					operator->() const
			{
				return (&(operator*()));
			}

			bidirectional_iterator	&operator++()
			{
				setnext();
				return (*this);
			}

			bidirectional_iterator	operator++(int)
			{
				bidirectional_iterator it = *this;
				setnext();
				return (it);
			}

			bidirectional_iterator	&operator--()
			{
				setprev();
				return (*this);
			}

			bidirectional_iterator	operator--(int)
			{
				bidirectional_iterator it = *this;
				setprev();
				return (it);
			}

			template<bool Iter1, bool Iter2, typename T>
			friend bool operator==(const bidirectional_iterator<Iter1, T> &lhs, const bidirectional_iterator<Iter2, T> &rhs)
			{
				return (lhs.node_ptr == rhs.node_ptr);
			}

			template<bool Iter1, bool Iter2, typename T>
			friend bool operator!=(const bidirectional_iterator<Iter1, T> &lhs, const bidirectional_iterator<Iter2, T> &rhs)
			{
				return (lhs.node_ptr != rhs.node_ptr);
			}

			operator bidirectional_iterator<true, value_type>() const
			{
				return (bidirectional_iterator<true, value_type>(this->node_ptr, this->root));
			}
	};
}
#endif