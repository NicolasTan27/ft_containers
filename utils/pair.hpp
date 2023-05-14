/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:24:40 by ntan              #+#    #+#             */
/*   Updated: 2022/10/19 15:40:19 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{

template <class T1, class T2>
struct pair
{
	typedef		T1	first_type;
	typedef		T2	second_type;

	T1	first;
	T2	second;

	pair() : first(), second() {};
	pair (const first_type& a, const second_type& b) : first(a), second(b) {};
	template <class U, class V>
	pair(const pair<U,V>& pr) : first(pr.first), second(pr.second) {};
	~pair() {};
	
	pair	&operator=(const pair &pr)
	{
		// if (this != pr)
		// {
		// 	this->~pair()
			return (*(new(this) pair(pr)));
		// }
		// first = pr.first;
		// second = pr.second;
		// return (*this);
	}
};
	
template <class T1, class T2>
bool operator==(const pair<T1, T2> & x, const pair<T1, T2> & y)
{
	return (x.first == y.first && x.second == x.second);
}

template <class T1, class T2>
bool operator!=(const pair<T1, T2> & x, const pair<T1, T2> & y)
{
	return !(x == y);
}

template <class T1, class T2>
bool operator<(const pair<T1, T2> & x, const pair<T1, T2> & y)
{
	return (x.first < y.first || (!(y.first < x.first) && x.second < y.second));
}

template <class T1, class T2>
bool operator>(const pair<T1, T2> & x, const pair<T1, T2> & y)
{
	return (y < x);
}

template <class T1, class T2>
bool operator<=(const pair<T1, T2> & x, const pair<T1, T2> & y)
{
	return !(y < x);
}

template <class T1, class T2>
bool operator>=(const pair<T1, T2> & x, const pair<T1, T2> & y)
{
	return !(x < y);
}

// MAKE PAIR //

template <class T1, class T2>
pair<T1, T2>	make_pair(T1 x, T2 y)
{
	return (pair<T1, T2>(x, y));
}

template <class T1, class T2>
std::ostream &operator<<(std::ostream &flux, const pair<T1, T2> & pair)
{
	flux << "[" << pair.first << "] = " << pair.second;
	return (flux);
}

} // namespace ft

#endif