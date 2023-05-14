/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:40:26 by ntan              #+#    #+#             */
/*   Updated: 2022/09/24 16:06:53 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "iterators_traits.hpp"

namespace ft
{

template < class Iterator >
class iterator
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
		iterator() : current() {};
		
		explicit iterator(iterator_type src) : current(src) {};
		
		template <class Iter>
		iterator(const iterator<Iter>& it) : current(it.base()) {};

		// BASE //
		iterator_type	base() const
		{
			return current; 
		}

		// REFERENCE OPERATORS //
		reference	operator*() const
		{
			// Iterator	tmp = current;
			return (*current);
		}

		pointer		operator->() const
		{
			return ( &(operator*()) );
		}
		
		// INCREMENTAL/DECREMENTAL OPERATORS //
		iterator &operator++() // POST INCREMENT
		{
			++current;
			return (*this);
		}
		
		iterator operator++(int) // PAST INCREMENT
		{
			iterator	tmp = *this;
			++current;
			return (tmp);
		}

		iterator &operator--() // POST INCREMENT
		{
			--current;
			return (*this);
		}

		iterator operator--(int) // PAST INCREMENT
		{
			iterator	tmp = *this;
			--current;
			return (tmp);
		}

		// SUB/ADD OPERATORS //
		iterator operator+(difference_type n) const
		{
			return (iterator(current + n));
		}

		iterator &operator+=(difference_type n)
		{
			current += n;
			return (*this);
		}

		iterator operator-(difference_type n) const
		{
			return (iterator(current - n));
		}

		iterator &operator-=(difference_type n)
		{
			current -= n;
			return (*this);
		}

		reference operator[](difference_type n) const
		{
			return (*(*this + n));
		}
};

template <class Iterator>
bool operator==(const iterator<Iterator>& lhs, const iterator<Iterator>& rhs)
{
	return (lhs.base() == rhs.base());
}
template <class IteratorL, class IteratorR>
bool operator==(const iterator<IteratorL>& lhs, const iterator<IteratorR>& rhs)
{
	return (lhs.base() == rhs.base());
}

template <class Iterator>
bool operator!=(const iterator<Iterator>& lhs,const iterator<Iterator>& rhs)
{
	return (lhs.base() != rhs.base());
}
template <class IteratorL, class IteratorR>
bool operator!=(const iterator<IteratorL>& lhs,const iterator<IteratorR>& rhs)
{
	return (lhs.base() != rhs.base());
}

template <class Iterator>
bool operator<(const iterator<Iterator>& lhs, const iterator<Iterator>& rhs)
{
	return (lhs.base() < rhs.base());
}
template <class IteratorL, class IteratorR>
bool operator<(const iterator<IteratorL>& lhs, const iterator<IteratorR>& rhs)
{
	return (lhs.base() < rhs.base());
}

template <class Iterator>
bool operator<= (const iterator<Iterator>& lhs, const iterator<Iterator>& rhs)
{
	return (lhs.base() <= rhs.base());
}
template <class IteratorL, class IteratorR>
bool operator<= (const iterator<IteratorL>& lhs, const iterator<IteratorR>& rhs)
{
	return (lhs.base() <= rhs.base());
}

template <class Iterator>
bool operator>  (const iterator<Iterator>& lhs, const iterator<Iterator>& rhs)
{
	return (lhs.base() > rhs.base());
}
template <class IteratorL, class IteratorR>
bool operator>  (const iterator<IteratorR>& lhs, const iterator<IteratorL>& rhs)
{
	return (lhs.base() > rhs.base());
}

template <class Iterator>
bool operator>= (const iterator<Iterator>& lhs, const iterator<Iterator>& rhs)
{
	return (lhs.base() >= rhs.base());
}
template <class IteratorL, class IteratorR>
bool operator>= (const iterator<IteratorR>& lhs, const iterator<IteratorL>& rhs)
{
	return (lhs.base() >= rhs.base());
}

template <class Iterator>
typename iterator<Iterator>::difference_type operator-( const iterator<Iterator>& lhs, const iterator<Iterator>& rhs )
{
	return (lhs.base() - rhs.base());
}
template <class IteratorL, class IteratorR>
typename iterator<IteratorL>::difference_type operator-( const iterator<IteratorL>& lhs, const iterator<IteratorR>& rhs )
{
	return (lhs.base() - rhs.base());
}

template <class Iterator>
typename iterator<Iterator>::difference_type operator+( const iterator<Iterator>& lhs, const iterator<Iterator>& rhs )
{
	return (lhs.base() + rhs.base());
}
template <class IteratorL, class IteratorR>
typename iterator<IteratorL>::difference_type operator+( const iterator<IteratorL>& lhs, const iterator<IteratorR>& rhs )
{
	return (lhs.base() + rhs.base());
}


template <class Iterator>  
iterator<Iterator> operator+(typename iterator<Iterator>::difference_type n, const iterator<Iterator>& it)
{
	return (iterator<Iterator>(it.base() + n));	
}

template <class Iterator>  
iterator<Iterator> operator-(typename iterator<Iterator>::difference_type n, const iterator<Iterator>& it)
{
	return (iterator<Iterator>(it.base() - n));	
}

}
#endif