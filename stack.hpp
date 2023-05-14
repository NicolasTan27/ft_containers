/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:17:20 by ntan              #+#    #+#             */
/*   Updated: 2022/10/26 17:27:13 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"
#include "utils/ft_containers_utils.hpp"
#include <stdexcept>
#include <memory>
#include <iostream>

namespace ft {
	
template < typename T, typename Sequence = ft::vector<T> >
class stack {

	public:
		typedef typename Sequence::value_type                value_type;
		typedef          Sequence                            container_type;
		typedef typename Sequence::size_type                 size_type;
		typedef typename Sequence::reference                 reference;
		typedef typename Sequence::const_reference           const_reference;
	
	protected:
		Sequence c;
	
	public :
		explicit stack(const container_type& ctnr = container_type()) : c(ctnr) {};

		// stack& operator=( const stack& other ); // implicitly declared

		bool	empty() const
		{
			return (c.empty());
		}

		size_type	size() const
		{
			return (c.size());
		}

		reference top()
		{
			// if (!empty())
			return (c.back());
		}
		
		const_reference top() const
		{
			// if (!empty())
			return (c.back());
		}
		
		void	push(const value_type& x)
		{
			c.push_back(x);
		}

		void	pop()
		{
			c.pop_back();
		}

		template <typename T1, typename Seq1>
		friend bool operator==(const stack<T1, Seq1>&x, const stack<T1, Seq1>&y);
		template <typename T1, typename Seq1>
		friend bool operator<(const stack<T1, Seq1>&x, const stack<T1, Seq1>&y);

}; // end of stack

template <typename T, typename Seq>
bool	operator==(const stack<T, Seq>& x, const stack<T, Seq>& y)
{ return (x.c == y.c); }

template <typename T, typename Seq>
bool	operator!=(const stack<T, Seq>& x, const stack<T, Seq>& y)
{ return !(x == y); }

template <typename T, typename Seq>
bool	operator<(const stack<T, Seq>& x, const stack<T, Seq>& y)
{ return (x.c < y.c); }

template <typename T, typename Seq>
bool	operator<=(const stack<T, Seq>& x, const stack<T, Seq>& y)
{ return !(y < x); }

template <typename T, typename Seq>
bool	operator>(const stack<T, Seq>& x, const stack<T, Seq>& y)
{ return (y < x); }

template <typename T, typename Seq>
bool	operator>=(const stack<T, Seq>& x, const stack<T, Seq>& y)
{ return !(x < y); }

} // end of namepsace ft

#endif