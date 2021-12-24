#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

namespace ft
{

	template <bool B, class T, class U>
	struct enable_because
	{
		typedef T type;
	};

	template <class T, class U>
	struct enable_because<false, T, U>
	{
		typedef U type;
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
								red(n.red),
								value(n.value){}
		
		Node(const Node *n, const Data &rvalue) : node_parent(n),
												node_left(NULL),
												node_right(NULL),
												red(0),
												value(rvalue) {}

		
		Node(const Data &v) : node_parent(NULL),
											node_left(NULL),
											node_right(NULL),
											red(0),
											value(v) {}

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

	template <bool Compare, typename T>
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
			typedef Node<value_type> *node_pointer;

		private:
			node_pointer	node_ptr;
			node_pointer	root;

			void setnext()
			{
				if (!this->node_ptr)
				{
					this->node_ptr = this->root;
					if (this->node_ptr)
					{
						while (this->node_ptr->node_left)
							this->node_ptr = this->node_ptr->node_left;
					}
					return ;
				}
				if (this->node_ptr->node_right)
				{
					this->node_ptr = this->node_ptr->node_right;
					while (this->node_ptr->node_left)
						this->node_ptr = this->node_ptr->node_left;
				}
				else
				{
					while (this->node_ptr->node_parent && this->node_ptr == this->node_ptr->node_parent->node_right)
						this->node_ptr = this->node_ptr->node_parent;
					this->node_ptr = this->node_ptr->node_parent;
				}
			}

			void setprev()
			{
				if (!this->node_ptr)
				{
					this->node_ptr = this->root;
					if (this->node_ptr)
					{
						while (this->node_ptr->node_right)
							this->node_ptr = this->node_ptr->node_right;
					}
					return ;
				}
				if (this->node_ptr->node_left)
				{
					this->node_ptr = this->node_ptr->node_left;
					while (this->node_ptr->node_right)
						this->node_ptr = this->node_ptr->node_right;
				}
				else
				{
					while (this->node_ptr->node_parent && this->node_ptr == this->node_ptr->node_parent->node_left)
						this->node_ptr = this->node_ptr->node_parent;
					this->node_ptr = this->node_ptr->node_parent;
				}
				
			}

		public:
			bidirectional_iterator() : node_ptr(NULL), root(NULL){}

			bidirectional_iterator(const bidirectional_iterator &other) : node_ptr(other.node_ptr), root(other.root)
			{
			}

			bidirectional_iterator(node_pointer node_ptr, node_pointer root) : node_ptr(node_ptr), root(root)
			{
				// this->node_ptr = node_ptr;
				// this->root = root;
			}

			virtual ~bidirectional_iterator() {}

			bidirectional_iterator	&operator=(const bidirectional_iterator &other)
			{
				if (this != &other)
				{
					this->node_ptr = other.node_ptr;
					this->root = root;
				}
				return (*this);
			}

			node_pointer base()
			{
				return (this->node_ptr);
			}

			node_pointer base() const
			{
				return (this->node_ptr);
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

			template<bool Iter1, bool Iter2, typename U>
			friend bool operator==(const bidirectional_iterator<Iter1, U> &lhs, const bidirectional_iterator<Iter2, U> &rhs)
			{
				return (lhs.node_ptr == rhs.node_ptr);
			}

			template<bool Iter1, bool Iter2, typename U>
			friend bool operator!=(const bidirectional_iterator<Iter1, U> &lhs, const bidirectional_iterator<Iter2, U> &rhs)
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