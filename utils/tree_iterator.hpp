/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:34:47 by ntan              #+#    #+#             */
/*   Updated: 2022/10/21 19:53:57 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

# include "iterators_traits.hpp"
# include <memory>
namespace ft
{

template <typename N, typename V>
struct tree_iterator
{
	typedef typename 	ft::iterator_traits<N>::value_type			node_value_type;
	typedef typename	ft::iterator_traits<N>::pointer				node_pointer;
	typedef typename	ft::iterator_traits<N>::reference			node_reference;
	typedef typename	ft::iterator_traits<N>::difference_type		node_difference_type;
	typedef typename	ft::iterator_traits<N>::iterator_category	node_iterator_category;
	
	typedef				V											value_type;
	typedef				V*											pointer;
	typedef				V&											reference;
	typedef				ptrdiff_t									difference_type;
	typedef				std::bidirectional_iterator_tag				iterator_category;

	typedef				tree_iterator						self;
	// typedef					T								Link_type;

	// Attributes
	N	node;
	N	end_node;

	// Member Functions
	tree_iterator() : node(), end_node() {}

	explicit tree_iterator(N x, N end_node) : node(x), end_node(end_node) {}

	template <class N1, class V2>
	tree_iterator(const tree_iterator<N1, V2> &x) : node(x.base()), end_node(x.getEnd()) {}

	~tree_iterator() {}

	template <class T1, class T2>
	tree_iterator &operator=(const tree_iterator<T1, T2> &x)
	{
		node = x.base();
		end_node = x.getEnd();
		return (*this);
	}
	
	N base() const
	{
		return (node);
	}

	N getEnd() const
	{
		return (end_node);
	}
	
	reference operator*() const
	{
		return (node->value);
	}

	pointer	operator->() const
	{
		return (std::__addressof(node->value));
	}

	self	&operator++()
	{
		if (node->right != NULL)
		{
			node = node->right;
			while (node->left != NULL)
				node = node->left;
		}
		else
		{
			N y = node->parent;
			while (node == y->right)
			{
				node = y;
				y = y->parent;
			}
			if (node->right != y)
				node = y;
		}
		return (*this);
		// node = node->node_increment(node);
		// return (*this);
	}

	self	operator++(int)
	{
		self tmp = *this;
		// node = node->node_increment(node);
		this->operator++();
		// std::cout << "node : " << node->value << std::endl;
		return (tmp);
	}

	self	&operator--()
	{
		if (node->left != NULL)
		{
			node = node->left;
			while (node->right != NULL)
				node = node->right;
		}
		else
		{
			N y = node->parent;
			while (node == y->left)
			{
				node = y;
				y = y->parent;
			}
			if (node->left != y)
				node = y;
		}
		return (*this);
		// node = node->node_decrement(node);
		// return (*this);
	}

	self	operator--(int)
	{
		self tmp = *this;
		// node = node->node_decrement(node);
		this->operator--();
		return (tmp);
	}

	bool	operator==(const self& x) const
	{
		return (node == x.node);
	}

	bool	operator!=(const self& x) const
	{
		return (node != x.node);
	}

}; // end of tree_iterator

template <typename N, typename V>
bool	operator==(const tree_iterator<N, V> & x, const tree_iterator<N, V> & y)
{
	return (x.base() == y.base());
}

template <typename N, typename V>
bool	operator!=(const tree_iterator<N, V> & x, const tree_iterator<N, V> & y)
{
	return (x.base() != y.base());
}

} //end of namespace ft

#endif