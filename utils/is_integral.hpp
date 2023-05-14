/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:40:56 by ntan              #+#    #+#             */
/*   Updated: 2022/09/11 15:32:00 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft
{

/// INTEGRAL CONSTANT ///
template <class T, T v>
struct integral_constant 
{
	static const	 	T 						value = v;
	typedef 			T 						value_type;
	typedef 			integral_constant<T,v> 	type;
	// constexpr operator T() { return v; }
};

typedef integral_constant<bool,false> false_type;
typedef integral_constant<bool,true> true_type;

/// IS_INTEGRAL ///

template <class T>	
struct is_integral : public false_type {};

template <class T>	
struct is_integral<const T> : public is_integral<T> {};

template <class T>	
struct is_integral<volatile T> : public is_integral<T> {};

template <class T>	
struct is_integral<const volatile T> : public is_integral<T> {};



template<>
struct is_integral<bool> : public true_type {};
template<>
struct is_integral<char> : public true_type {};
// template<>
// struct is_integral<char16_t> : public true_type {};
// template<>
// struct is_integral<char32_t> : public true_type {};
template<>
struct is_integral<wchar_t> : public true_type {};
template<>
struct is_integral<signed char> : public true_type {};
template<>
struct is_integral<short int> : public true_type {};
template<>
struct is_integral<int> : public true_type {};
template<>
struct is_integral<long int> : public true_type {};
template<>
struct is_integral<long long int> : public true_type {};
template<>
struct is_integral<unsigned char> : public true_type {};
template<>
struct is_integral<unsigned short int> : public true_type {};
template<>
struct is_integral<unsigned int> : public true_type {};
template<>
struct is_integral<unsigned long int> : public true_type {};
template<>
struct is_integral<unsigned long long int> : public true_type {};

} // namespace fr

#endif