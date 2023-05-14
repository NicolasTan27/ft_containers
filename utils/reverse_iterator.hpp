/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:28:12 by ntan              #+#    #+#             */
/*   Updated: 2022/09/24 15:12:16 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

// #include <iterator>
// #include <cstddef>
#include "iterators_traits.hpp"

namespace ft
{

template < class Iterator >
class reverse_iterator
{
	public :
		typedef				Iterator											iterator_type;
		typedef typename 	ft::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename 	ft::iterator_traits<Iterator>::value_type			value_type;
		typedef typename	ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename	ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename	ft::iterator_traits<Iterator>::reference			reference;

	protected :
		Iterator	current;

	public :
		// CONSTRUCTORS //
		reverse_iterator() : current() {};
		
		explicit reverse_iterator(iterator_type src) : current(src) {};
		
		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter>& rev_it) : current(rev_it.base()) {};

		// BASE //
		iterator_type	base() const
		{
			return current; 
		}

		// REFERENCE OPERATORS //
		reference	operator*() const
		{
			Iterator	tmp = current;
			return (*--tmp);
		}

		pointer		operator->() const
		{
			return ( &(operator*()) );
		}
		
		// INCREMENTAL/DECREMENTAL OPERATORS //
		reverse_iterator &operator++() // POST INCREMENT
		{
			--current;
			return (*this);
		}
		
		reverse_iterator operator++(int) // PAST INCREMENT
		{
			reverse_iterator	tmp = *this;
			--current;
			return (tmp);
		}

		reverse_iterator &operator--() // POST INCREMENT
		{
			++current;
			return (*this);
		}

		reverse_iterator operator--(int) // PAST INCREMENT
		{
			reverse_iterator	tmp = *this;
			++current;
			return (tmp);
		}

		// SUB/ADD OPERATORS //
		reverse_iterator operator+(difference_type n) const
		{
			return (reverse_iterator(current - n));
		}

		reverse_iterator &operator+=(difference_type n)
		{
			current -= n;
			return (*this);
		}

		reverse_iterator operator-(difference_type n) const
		{
			return (reverse_iterator(current + n));
		}

		reverse_iterator &operator-=(difference_type n)
		{
			current += n;
			return (*this);
		}

		reference operator[](difference_type n) const
		{
			return (*(*this + n));
		}
};

template <class Iterator>
bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
{
	return (lhs.base() == rhs.base());
}
template <class IteratorL, class IteratorR>
bool operator==(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs)
{
	return (lhs.base() == rhs.base());
}

template <class Iterator>
bool operator!=(const reverse_iterator<Iterator>& lhs,const reverse_iterator<Iterator>& rhs)
{
	return (lhs.base() != rhs.base());
}
template <class IteratorL, class IteratorR>
bool operator!=(const reverse_iterator<IteratorL>& lhs,const reverse_iterator<IteratorR>& rhs)
{
	return (lhs.base() != rhs.base());
}

template <class Iterator>
bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
{
	return (rhs.base() < lhs.base());
}
template <class IteratorL, class IteratorR>
bool operator<(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs)
{
	return (rhs.base() < lhs.base());
}

template <class Iterator>
bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
{
	return (!(rhs < lhs));
}
template <class IteratorL, class IteratorR>
bool operator<= (const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs)
{
	return (!(rhs < lhs));
}

template <class Iterator>
bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
{
	return (rhs < lhs);
}
template <class IteratorL, class IteratorR>
bool operator>  (const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs)
{
	return (rhs < lhs);
}

template <class Iterator>
bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
{
	return (!(lhs < rhs));
}
template <class IteratorL, class IteratorR>
bool operator>= (const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs)
{
	return (!(lhs < rhs));
}

template <class Iterator>
typename reverse_iterator<Iterator>::difference_type operator-( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs )
{
	return (rhs.base() - lhs.base());
}
template <class IteratorL, class IteratorR>
typename reverse_iterator<IteratorL>::difference_type operator-( const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs )
{
	return (rhs.base() - lhs.base());
}

template <class Iterator>
typename reverse_iterator<Iterator>::difference_type operator+( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs )
{
	return (lhs.base() + rhs.base());
}
template <class IteratorL, class IteratorR>
typename reverse_iterator<IteratorL>::difference_type operator+( const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs )
{
	return (lhs.base() + rhs.base());
}

template <class Iterator>  
reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
{
	return (reverse_iterator<Iterator>(rev_it.base() - n));	
}

template <class Iterator>  
reverse_iterator<Iterator> operator-(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
{
	return (reverse_iterator<Iterator>(rev_it.base() + n));	
}

}
#endif