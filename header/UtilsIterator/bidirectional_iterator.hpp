#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

namespace ft
{
	template<class Data>
	struct Node
	{
		private:
			Node();
		
		public:
			Node	*node_parent;
			Node	*node_left;
			Node	*node_right;
			int		color;
			Data	value;

		~Node()
		{
		}

		Node(const Node &n) : node_parent(n.node_parent),
								node_left(n.node_left),
								node_right(n.node_right),
								color(n.color)
								value(n.value){}
		
		Node(const Node *n, const Data &rvalue) : node_parent(n),
												node_left(NULL),
												node_right(NULL),
												color(0),
												value(rvalue) {}

		Node &operator=(const Node &other)
		{
			if (this != other)
			{
				this->color = other.color;
				this->node_left = other.node_left;
				this->node_parent = other.node_parent;
				this->node_right = other.node_right;
				this->value = other.value;
			}
			return (*this);
		}
	};

	template <typename T, class Compare>
	class bidirectional_iterator
	{
		public:
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer			pointer;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference			reference;

		private:

	};
}
#endif