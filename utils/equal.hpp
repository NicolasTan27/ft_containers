/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:57:18 by ntan              #+#    #+#             */
/*   Updated: 2022/09/25 13:45:37 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP

namespace ft
{
	
template <class InputIterator1, class InputIterator2>
bool	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
{
	while (first1!=last1) 
	{
		if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
			return false;
		++first1;
		++first2;
	}
	return true;
}

template <class InputIterator1, class InputIterator2, class BinaryPredicate>
bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
{
	while (first1!=last1) 
	{
		if (!pred(*first1,*first2)) 
			return false;
		++first1;
		++first2;
	}
	return true;
}

} // namespace ft

#endif