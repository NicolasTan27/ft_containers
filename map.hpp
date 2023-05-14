/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 13:34:16 by ntan              #+#    #+#             */
/*   Updated: 2022/10/27 17:12:45 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <stdexcept>
# include <memory>
# include <functional>
# include <iostream>
# include "utils/ft_containers_utils.hpp"
# include "utils/binary_tree.hpp"
// # include "vector.hpp"

namespace ft
{
	
template < typename Key, typename T, typename Compare = std::less<Key>, typename Alloc = std::allocator< ft::pair<const Key, T> > > 
class map
{
	public :
		typedef					Key										key_type;
		typedef					T										mapped_type;
		typedef					pair<const key_type, mapped_type>		value_type;
		typedef					Compare									key_compare;
		typedef					Alloc									allocator_type;
	
		typedef	typename		allocator_type::reference				reference;
		typedef	typename		allocator_type::const_reference			const_reference;
		typedef	typename		allocator_type::pointer					pointer;
		typedef	typename		allocator_type::const_pointer			const_pointer;	

		typedef					ptrdiff_t								difference_type;
		typedef					size_t									size_type;

		class value_compare {
			public :
				bool	operator()(const value_type& lhs, const value_type &rhs) const
				{
					return key_compare()(lhs.first, rhs.first);
				}
		};
	
		typedef					ft::Binary_tree<value_type, value_compare, allocator_type>	tree_type;
		// typedef					tree_type::node_ptr		node_ptr;
		typedef typename		tree_type::iterator						iterator;
		typedef typename		tree_type::const_iterator				const_iterator;
		typedef typename		tree_type::reverse_iterator				reverse_iterator;
		typedef typename		tree_type::const_reverse_iterator		const_reverse_iterator;

	private :
		tree_type			tree;
		allocator_type		alloc;

		key_compare			cmp;
		value_compare		value_cmp;

	public :
		/////////////
		/// UTILS ///
		/////////////

		// void	treeInorder()
		// {
		// 	tree.inorder(tree.get_root());
		// }

		// void	print2d()
		// {
		// 	tree.print2D();
		// }
		
		//////////////////////////////////
		/// CONSTRUCTORS / DESTRUCTORS ///
		//////////////////////////////////

		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		: tree(), alloc(alloc), cmp(comp), value_cmp(value_compare()) {}

		template <class InputIterator>  
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		: tree(), alloc(alloc), cmp(comp), value_cmp(value_compare()) 
		{
			insert(first, last);
		}
	
		map (const map& x) : tree(x.tree), alloc(x.get_allocator()), cmp(x.key_comp()), value_cmp(x.value_comp())
		{}

		~map() 
		{
			clear();
		}
	
		map& operator=(const map& x)
		{
			clear();
			tree = x.tree;
			alloc = x.get_allocator();
			cmp = x.key_comp();
			value_cmp = x.value_comp();
			return (*this);
		}

		/////////////////
		/// ITERATORS ///
		/////////////////

		iterator begin()
		{ return (tree.begin()); }
		
		const_iterator begin() const
		{ return (tree.begin()); }

		iterator end()
		{ return (tree.end()); }
		
		const_iterator end() const
		{ return (tree.end()); }

		reverse_iterator rbegin()
		{ return (tree.rbegin()); }
		
		const_reverse_iterator rbegin() const
		{ return (tree.rbegin()); }

		reverse_iterator rend()
		{ return (tree.rend()); }
		
		const_reverse_iterator rend() const
		{ return (tree.rend()); }
		
		////////////////
		/// CAPACITY ///
		////////////////

		bool empty() const
		{
			return(tree.empty());
		}

		size_type size() const
		{
			return (tree.size());
		}

		size_type max_size() const
		{
			return (tree.max_size());
		}

		//////////////////////
		/// ELEMENT ACCESS ///
		//////////////////////

		mapped_type	&operator[](const key_type &k)
		{
			iterator i = lower_bound(k);
			if (i == end() || key_comp()(k, (*i).first))
				i = insert(ft::make_pair(k, mapped_type())).first;
			return (*i).second;
		}
		
		mapped_type& at (const key_type& k)
		{
			iterator i = lower_bound(k);
			if (i == end() || key_comp()(k, (*i).first))
				throw (std::out_of_range("map::at"));
			return (*i).second;
		}

		const mapped_type& at (const key_type& k) const
		{
			const_iterator i = lower_bound(k);
			if (i == end() || key_comp()(k, (*i).first))
				throw (std::out_of_range("map::at"));
			return (*i).second;
		}
		
		/////////////////
		/// MODIFIERS ///
		/////////////////

		pair<iterator,bool> insert (const value_type& val)
		{
			return (tree.insertNode(val));
		}

		iterator insert (iterator position, const value_type& val)
		{
			return (tree.insertHint(position, val).first);
		}

		template <class InputIterator> 
		void insert (InputIterator first, InputIterator last)
		{
			tree.insertRange(first, last);
		}

		void erase (iterator position)
		{
			tree.del(*position);
		}

		size_type erase (const key_type& k)
		{
			return (tree.del(ft::make_pair(k, mapped_type())));
		}

		void erase (iterator first, iterator last)
		{
			tree.erase_range(first, last);
		}

		void swap(map &x)
		{
			tree.swap(x.tree);
			allocator_type		tmp_alloc = alloc;
			key_compare			tmp_cmp = cmp;
			value_compare		tmp_value_cmp = value_cmp;

			alloc = x.alloc;
			cmp = x.cmp;
			value_cmp = x.value_cmp;

			x.alloc = tmp_alloc;
			x.cmp = tmp_cmp;
			x.value_cmp = tmp_value_cmp;
		}

		void clear()
		{
			tree.clear();
		}

		/////////////////
		/// OBSERVERS ///
		/////////////////

		key_compare key_comp() const
		{
			return (cmp);
		}

		value_compare value_comp() const
		{
			return (value_cmp);
		}

		//////////////////
		/// OPERATIONS ///
		//////////////////
		
		iterator find(const key_type& k)
		{
			return (tree.find(ft::make_pair(k, mapped_type())));
		}
		
		const_iterator find (const key_type& k) const
		{
			return (const_iterator(tree.find(ft::make_pair(k, mapped_type()))));
		}

		size_type count(const Key& k) const
		{
			return (tree.count(ft::make_pair(k, T())));
		}

		iterator lower_bound(const key_type& k)
		{
			return (tree.lower_bound(ft::make_pair(k, T())));
		}
		
		const_iterator lower_bound (const key_type& k) const
		{
			return (tree.lower_bound(ft::make_pair(k, T())));
		}

		iterator upper_bound (const key_type& k)
		{
			return (tree.upper_bound(ft::make_pair(k, T())));
		}
		
		const_iterator upper_bound (const key_type& k) const
		{
			return (tree.upper_bound(ft::make_pair(k, T())));
		}

		pair<iterator,iterator> equal_range(const key_type& k)
		{
			return (ft::make_pair(lower_bound(k), upper_bound(k)));
		}

		pair<const_iterator,const_iterator> equal_range(const key_type& k) const
		{
			return (ft::make_pair(lower_bound(k), upper_bound(k)));
		}
		
		/////////////////
		/// ALLOCATOR ///
		/////////////////

		allocator_type	get_allocator() const
		{
			return (alloc);
		}
		
		template < typename Key1, typename T1, typename Compare1, typename Alloc1 > 
		friend bool	operator==(const map<Key1, T1, Compare1, Alloc1> & x, const map<Key1, T1, Compare1, Alloc1> & y);
		template < typename Key1, typename T1, typename Compare1, typename Alloc1 > 
		friend bool	operator<(const map<Key1, T1, Compare1, Alloc1> & x, const map<Key1, T1, Compare1, Alloc1> & y);

}; // end of class map

	template < typename Key, typename T, typename Compare, typename Alloc > 
	bool	operator==(const map<Key, T, Compare, Alloc> & x, const map<Key, T, Compare, Alloc> & y)
	{
		return (x.tree == y.tree);
	}
	
	template < typename Key, typename T, typename Compare, typename Alloc > 
	bool	operator<(const map<Key, T, Compare, Alloc> & x, const map<Key, T, Compare, Alloc> & y)
	{
		return (x.tree < y.tree);
	}

	template < typename Key, typename T, typename Compare, typename Alloc > 
	bool	operator!=(const map<Key, T, Compare, Alloc> & x, const map<Key, T, Compare, Alloc> & y)
	{
		return !(x == y);
	}
	
	template < typename Key, typename T, typename Compare, typename Alloc > 
	bool	operator>(const map<Key, T, Compare, Alloc> & x, const map<Key, T, Compare, Alloc> & y)
	{
		return (y < x);
	}
	
	template < typename Key, typename T, typename Compare, typename Alloc > 
	bool	operator<=(const map<Key, T, Compare, Alloc> & x, const map<Key, T, Compare, Alloc> & y)
	{
		return !(y < x);
	}

	template < typename Key, typename T, typename Compare, typename Alloc > 
	bool	operator>=(const map<Key, T, Compare, Alloc> & x, const map<Key, T, Compare, Alloc> & y)
	{
		return !(x < y);
	}
	
	template < typename Key, typename T, typename Compare, typename Alloc > 
	void	swap(map<Key, T, Compare, Alloc> & x, map<Key, T, Compare, Alloc> & y)
	{
		x.swap(y);
	}
	
} // end of namespace ft
#endif