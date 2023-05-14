/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:50:44 by ntan              #+#    #+#             */
/*   Updated: 2022/10/27 17:15:54 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_HPP
# define BINARY_TREE_HPP

# include <stdexcept>
# include <memory>
# include <iostream>
# include <functional>
# include <cstddef>
# include "iterators_traits.hpp"
# include "reverse_iterator.hpp"
# include "node.hpp"
# include "tree_iterator.hpp"
# include "../vector.hpp"
# include <vector>

namespace ft {

template < typename V, typename Compare = std::less<V>, typename Alloc = std::allocator<V> >
class Binary_tree
{
	public :
		typedef					V					value_type;
		typedef					Alloc 				allocator_type;
		typedef					ptrdiff_t			difference_type;
		typedef					size_t				size_type;

		typedef					Node<value_type>								node_type;
		typedef typename		Alloc::template rebind<node_type>::other		node_allocator;
		typedef typename		node_allocator::pointer							node_ptr;
		typedef typename		node_allocator::const_pointer 					node_const_ptr;
		typedef typename		node_allocator::reference						node_ref;
		typedef typename		node_allocator::const_reference 				node_const_ref;

		typedef					ft::tree_iterator<node_ptr, V>						iterator;
		typedef					ft::tree_iterator<node_ptr, const V>				const_iterator;
		typedef					ft::reverse_iterator<iterator>						reverse_iterator;
		typedef					ft::reverse_iterator<const_iterator>				const_reverse_iterator;

	private :
		node_ptr		root;
		node_ptr		end_node;
		size_type		_size;

		allocator_type	alloc;
		node_allocator	node_alloc;

		Compare			key_compare; 

	public :

		Binary_tree() : root(NULL), end_node(NULL), _size(0), alloc(allocator_type()), node_alloc(node_allocator()), key_compare(Compare())
		{
			// root = new_node(value_type());
			end_node = new_node(value_type());
		}
		
		
		Binary_tree(const Binary_tree &src) : root(NULL), end_node(NULL), _size(0), alloc(allocator_type()), node_alloc(node_allocator()), key_compare(Compare())
		{
			// root = new_node(value_type()); 
			end_node = new_node(value_type());
			// insertRange(src.begin(), src.end());
			root = cloneTree(src.get_root(), NULL, src.get_end());
			if (root != NULL)
			{
				node_ptr tmp = maxValueNode(root);
				tmp->right = end_node;
				end_node->setParent(tmp);
			}
			_size = src._size;
		}

		Binary_tree	&operator=(const Binary_tree &x)
		{
			if (root != NULL || _size != 0)
			{
				clear();
				end_node = new_node(value_type());
			}
			root = cloneTree(x.get_root(), NULL, x.get_end());
			if (root != NULL)
			{
				
				node_ptr tmp = maxValueNode(root);
				tmp->right = end_node;
				end_node->setParent(tmp);
			}
			_size = x._size;
			return (*this);
		}

		node_allocator getNodeAlloc() const {return (node_alloc);}
		allocator_type getAlloc() const {return (alloc);}
		Compare		   getComp() const {return (key_compare);}

		~Binary_tree() 
		{
			// if (_size == 0)
				freeNode(end_node);
			// else	
				clear();
		}

		void swap(Binary_tree& x)
		{
			node_ptr		tmp_root = root;
			node_ptr		tmp_end_node = end_node;
			size_type		tmp__size = _size;
			allocator_type	tmp_alloc = alloc;
			node_allocator	tmp_node_alloc = node_alloc;
			Compare			tmp_key_compare = key_compare;

			root = x.root;
			end_node = x.end_node;
			_size = x._size;
			alloc = x.alloc;
			node_alloc = x.node_alloc;
			key_compare = x.key_compare;

			x.root = tmp_root;
			x.end_node = tmp_end_node;
			x._size = tmp__size;
			x.alloc = tmp_alloc;
			x.node_alloc = tmp_node_alloc;
			x.key_compare = tmp_key_compare;
		}
		
		node_ptr get_root() const
		{ return (root); }

		node_ptr get_end() const
		{ return (end_node); }

		bool	empty()	const
		{
			return (_size == 0);
		}

		size_type size() const
		{
			return (this->_size);
		}

		size_type max_size() const
		{
			return (node_alloc.max_size());
		}

		node_ptr minValueNode(node_ptr node)
		{
			node_ptr	current = node;
			while (current && current->left)
			{
				current = current->left;
			}
			return (current);
		}

		node_const_ptr minValueNode(node_const_ptr node)
		{
			node_ptr	current = node;
			while (current && current->left)
			{
				current = current->left;
			}
			return (current);
		}

		node_ptr maxValueNode(node_ptr node)
		{
			node_ptr current = node;
			while (current && current->right && current->right != end_node)
			{
				current = current->right;
			}
			return (current);
		}

		node_const_ptr maxValueNode(node_const_ptr node)
		{
			node_ptr current = node;
			while (current && current->right && current->right != end_node )
			{
				current = current->right;
			}
			return (current);
		}

		void	freeNode(node_ptr node)
		{
			node_alloc.destroy(node);
			node_alloc.deallocate(node, 1);
		}

		node_ptr new_node(const value_type& value, node_ptr left = NULL, node_ptr right = NULL)
		{
			node_ptr node = node_alloc.allocate(1);
			node_alloc.construct(node, value);
			// node->parent = parent;
			node->left = left;
			node->right = right; 
			return (node);
		}

		template<typename InputIterator>
		void	erase_range(InputIterator first, InputIterator last)
		{
			ft::vector<value_type> myvec;
			while (first != last)
				myvec.push_back(*(first++));
			for (size_type i = 0; i < myvec.size(); i++)
				del(myvec[i]);
		}

		template<typename InputIterator>
		void	insertRange(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				insertHint(end(), *first);
				first++;
			}
			// ft::vector<value_type> myvec(first, last);
			// for (size_type i = 0; i < myvec.size(); i++)
			// 	insertHint(end(), myvec[i]);
		}

		size_type	 del(const value_type& value)
		{
			if (searchNode(value))
			{
				// std::cout << "erasing : " << value << std::endl;
				// root = deleteNode(root, value);
				root = deleteNode(value);
				--_size;
				if (root != NULL && _size != 0)
				{	
					node_ptr tmp = maxValueNode(root);
					// std::cout << "tmp->value : " << tmp->value << std::endl;
					tmp->right = end_node;
					end_node->setParent(tmp);
				}
				return (1);
			}
			return (0);
		}

		node_ptr deleteNode(const value_type& value)
		{			
			node_ptr curr = root;
			node_ptr prev = NULL;

			if (curr == end_node || curr == NULL)
				return (root);
			while(curr != NULL)
			{
				if (key_compare(value, curr->value)) // == value < root->value
				{
					prev = curr;
					curr = curr->left;
				}
				else if (key_compare(curr->value, value)) // == root->value < value
				{
					prev = curr;
					curr = curr->right;
				}
				else
					break;
			}

			if (curr->left == NULL || curr->left == end_node || curr->right == NULL || curr->right == end_node)
			{
				node_ptr newCurr;
				if (curr->left == NULL || curr->left == end_node)
					newCurr = curr->right;
				else
					newCurr = curr->left;
				
				if (prev == NULL)
				{
					freeNode(curr);
					root = NULL;
					return (newCurr);
				}
					
				if (newCurr != NULL)
					newCurr->setParent(prev);
					
				if (curr == prev->left)
					prev->left = newCurr;
				else
					prev->right = newCurr;
				freeNode(curr);
			}
			else
			{
				node_ptr p = NULL;
				node_ptr temp;

				temp = curr->right;
				while (temp->left != NULL)
				{
					p = temp;
					temp = temp->left;
				}

				if (p != NULL)
				{
					if (temp->right)
						temp->right->setParent(p);
					p->left = temp->right;
				}
				else
				{
					if (temp->right)
						temp->right->setParent(curr);
					curr->right = temp->right;
				}
				curr->value = temp->value;
				freeNode(temp);
			}
			return (root);
		}
		
		ft::pair<iterator, bool> insertHint(iterator position, const value_type& value)
		{
			if (position == end() && root != NULL)
			{
				node_ptr max = end_node->parent;
				if (key_compare(max->value, value))
				{
					node_ptr new_val = new_node(value);
					max->right = new_val;
					new_val->setParent(max);
					new_val->right = end_node;
					end_node->setParent(new_val);
					++_size;
					return (ft::make_pair(iterator(new_val, end_node), true));
				}
			}
			return (insertNode(value));
		}
		
		ft::pair<iterator, bool> insertNode(const value_type& value)
		{
			node_ptr new_val = new_node(value);
			if (root == NULL || _size == 0)
			{
				root = new_val;
				new_val->right = end_node;
				end_node->setParent(new_val);
				_size++;
				return (ft::make_pair(iterator(root, end_node), true)); //return (root);
			}

			node_ptr prev = NULL;
			node_ptr tmp = root;
			while (tmp && tmp != end_node)
			{
				if (key_compare(value, tmp->value)) // == value < root->value
				{
					prev = tmp;
					tmp = tmp->left;
				}
				else if (key_compare(tmp->value, value)) // == root->value < value
				{
					prev = tmp;
					tmp = tmp->right;
				}
				else
				{
					freeNode(new_val);
					return (ft::make_pair(iterator(tmp, end_node), false));
				}
			}
			if	(key_compare(value, prev->value))
				prev->left = new_val;
			else
				prev->right = new_val;
			new_val->setParent(prev);
			_size++;
			if (new_val == maxValueNode(root))
			{
				new_val->right = end_node;
				end_node->setParent(new_val);
			}
			return (ft::make_pair(iterator(new_val, end_node), true));
		}

		// template <class InputIterator>
		// void	insertRange(InputIterator first, InputIterator last)
		// {
		// 	while (first != last)
		// 	{
		// 		insertNode(*first);
		// 		first++;
		// 	}
		// }

		node_ptr searchNode(const value_type& value) const
		{
			node_ptr tmp = root;
			while (tmp && tmp != end_node)
			{
				if (key_compare(value, tmp->value)) // == value < root->value
					tmp = tmp->left;
				else if (key_compare(tmp->value, value)) // == root->value < value
					tmp = tmp->right;
				else
					return (tmp);
			}
			return (NULL);
		}
		
		void inorder(node_ptr root)
		{
			if (root != NULL) 
			{
				iterator	mbeg = begin();
				iterator	mend = end();

				std::cout << "========" << std::endl;
				while (mbeg != mend)
				{
					std::cout << *mbeg <<  " | parent : " << mbeg.base()->parent << " | itself : " << mbeg.base() << " | left: " << mbeg.base()->left << " | right: " << mbeg.base()->right << std::endl;
					mbeg++;
				}
			}
		}

		void print2DUtil(node_ptr root, int space)
		{
			if (root == NULL)
				return;
		
			// Increase distance between levels
			space += 10;
		
			print2DUtil(root->right, space);

			std::cout << std::endl;
			for (int i = 10; i < space; i++)
				std::cout << " ";
			std::cout << root->value << "\n";
		
			print2DUtil(root->left, space);
		}
		
		void print2D()
		{
			print2DUtil(root, 0);
		}

		node_ptr cloneTree(node_ptr root, node_ptr parent, node_ptr end)
		{
			if (root == NULL || root == end)
				return (NULL);
			
			// (void)parent;
			node_ptr root_copy = new_node(root->value);
			root_copy->parent = parent;
			root_copy->left = cloneTree(root->left, root_copy, end);
			root_copy->right = cloneTree(root->right, root_copy, end);

			return (root_copy);
		}

		void clear()
		{
			destroyTree(root);
			root = NULL;
			_size = 0;
			// end_node = new_node(value_type());
		}

		void destroyTree(node_ptr node)
		{
			if (node != NULL && node != end_node)
			{
				destroyTree(node->left);
				destroyTree(node->right);
				freeNode(node);
				node = NULL;
			}
		}

		iterator find(const value_type &value) const
		{
			if (searchNode(value))
				return (iterator(searchNode(value), end_node));
			return (end());
		}

		size_type count(const value_type &value) const
		{
			if (this->searchNode(value))
				return (1);
			return (0);
		}

		iterator lower_bound(const value_type& value)
		{
			node_ptr current = root;
			node_ptr res = end_node;
			while (current != NULL && current != end_node)
			{
				if (!key_compare(current->value, value))
				{
					res = current;
					current = current->left;
				}
				else
					current = current->right;
			}
			return (iterator(res, end_node));
		}

		const_iterator lower_bound(const value_type& value) const
		{
			node_ptr current = root;
			node_ptr res = end_node;
			while (current != NULL && current != end_node)
			{
				if (!key_compare(current->value, value))
				{
					res = current;
					current = current->left;
				}
				else
					current = current->right;
			}
			return (const_iterator(res, end_node));
		}

		iterator	upper_bound(const value_type& value)
		{
			node_ptr current = root;
			node_ptr res = end_node;
			while (current != NULL && current != end_node)
			{
				if (key_compare(value, current->value))
				{
					res = current;
					current = current->left;
				}
				else
					current = current->right;
			}
			return (iterator(res, end_node));
		}

		const_iterator	upper_bound(const value_type& value) const
		{
			node_ptr current = root;
			node_ptr res = end_node;
			while (current != NULL && current != end_node)
			{
				if (key_compare(value, current->value))
				{
					res = current;
					current = current->left;
				}
				else
					current = current->right;
			}
			return (const_iterator(res, end_node));
		}

		/// ITERATORS ///

		iterator	begin()
		{
			if (root == NULL)
				return (iterator(end_node, end_node));
			return (iterator(root->min(root), end_node));
		}

		const_iterator	begin() const
		{
			if (root == NULL)
				return (const_iterator(end_node, end_node));
			return (const_iterator(root->min(root), end_node));
		}

		reverse_iterator	rbegin()
		{
			return (reverse_iterator(end()));
		}

		const_reverse_iterator	rbegin() const
		{
			return (const_reverse_iterator(end()));	
		}

		iterator	end()
		{
			return (iterator(end_node, end_node));
		}

		const_iterator	end() const
		{
			return (const_iterator(end_node, end_node));
		}

		reverse_iterator rend()
		{
			return (reverse_iterator(begin()));
		}

		const_reverse_iterator	rend() const
		{
			return (const_reverse_iterator(begin()));
		}

};

	template <typename V, typename Compare, typename Alloc>
	bool	operator==(const Binary_tree<V, Compare, Alloc> &x, const Binary_tree<V, Compare, Alloc> &y)
	{ 
		return (x.size() == y.size()) && (ft::equal(x.begin(), x.end(), y.begin()));
	}

	template <typename V, typename Compare, typename Alloc>
	bool	operator<(const Binary_tree<V, Compare, Alloc> &x, const Binary_tree<V, Compare, Alloc> &y)
	{ 
		return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}

	template <typename V, typename Compare, typename Alloc>
	bool	operator!=(const Binary_tree<V, Compare, Alloc> &x, const Binary_tree<V, Compare, Alloc> &y)
	{ 
		return !(x == y);
	}

	template <typename V, typename Compare, typename Alloc>
	bool	operator>(const Binary_tree<V, Compare, Alloc> &x, const Binary_tree<V, Compare, Alloc> &y)
	{ 
		return y == x;
	}
	
	template <typename V, typename Compare, typename Alloc>
	bool	operator<=(const Binary_tree<V, Compare, Alloc> &x, const Binary_tree<V, Compare, Alloc> &y)
	{ 
		return !(y < x);
	}

	template <typename V, typename Compare, typename Alloc>
	bool	operator>=(const Binary_tree<V, Compare, Alloc> &x, const Binary_tree<V, Compare, Alloc> &y)
	{ 
		return !(x < y);
	}
	
	template <typename V, typename Compare, typename Alloc>
	void	swap(Binary_tree<V, Compare, Alloc> &x, Binary_tree<V, Compare, Alloc> &y)
	{ 
		x.swap(y);
	}

} //end of namespace ft

#endif