/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:34:53 by ntan              #+#    #+#             */
/*   Updated: 2022/10/21 22:30:13 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

namespace ft
{
	
template <typename V>
struct Node
{
	V				value;
	Node			*parent;
	Node			*left;
	Node			*right;
	bool			color;

	Node() : value(NULL), parent(NULL), left(NULL), right(NULL) {}
	Node(const V &val) : value(val), parent(NULL), left(NULL), right(NULL) {}
	Node(const Node &other) : value(other.value), parent(other.parent), left(other.left), right(other.right) {}
	template<class V1>
	Node(const Node<V1> & x) : value(x.getValue()), parent(x.getParent()), left(x.getLeft()), right(x.getRight()) {}
	Node &operator=(const Node& x)
	{
		value = x.value;
		parent = x.parent;
		left = x.left;
		right = x.right;
	}

	~Node() {}

	typedef		Node<V>*		Base_ptr;
	typedef		const Node<V>* 	const_Base_ptr;

	Node *getParent() const { return (parent); }
	Node *getLeft() const { return (left); }
	Node *getRight() const {return (right); }	
	V	getValue() const { return (value); }	
	
	void	setParent(Node *node)
	{
		parent = node;
	}

	bool		isRightChild()
	{
		return (this->parent->right == this);
	}

	bool		isLeftChild()
	{
		return (this->parent->left == this);
	}

	Base_ptr min(Base_ptr x)
	{
		while (x->left != NULL)
			x = x->left;
		return (x);
	}

	Base_ptr max(Base_ptr x)
	{
		while (x->right != NULL)
			x = x->right;
		return (x);
	}
	
	Base_ptr node_increment(Base_ptr x)
	{
		if (x->right != NULL)
		{
			x = x->right;
			while (x->left != NULL)
			{
				x = x->left;
			}
		}
		else
		{
			Base_ptr y = x->parent;
			while (x == y->right)
			{
				x = y;
				y = y->parent;
			}
			if (x->right != y)
				x = y;
		}
		// std::cout << "end increment : " << x->getValue() << std::endl;
		return (x);
	}
	
	const_Base_ptr node_increment(const_Base_ptr x)
	{
		if (x->right != NULL)
		{
			x = x->right;
			while (x->left != NULL)
			{
				x = x->left;
			}
		}
		else
		{
			Base_ptr y = x->parent;
			while (x == y->right)
			{
				x = y;
				y = y->parent;
			}
			if (x->right != y)
				x = y;
		}
		return (x);
	}

	Base_ptr node_decrement(Base_ptr x)
	{
		if (x->left != NULL)
		{
			x = x->left;
			while (x->right != NULL)
				x = x->right;
		}
		else
		{
			Base_ptr y = x->parent;
			while (x == y->left)
			{
				x = y;
				y = y->parent;
			}
			if (x->left != y)
				x = y;
		}
		return (x);
	}

	const_Base_ptr node_decrement(const_Base_ptr x)
	{
		if (x->left != NULL)
		{
			x = x->left;
			while (x->right != NULL)
				x = x->right;
		}
		else
		{
			Base_ptr y = x->parent;
			while (x == y->left)
			{
				x = y;
				y = y->parent;
			}
			if (x->left != y)
				x = y;
		}
		return (x);
	}
};

}// end of namespace ft

#endif