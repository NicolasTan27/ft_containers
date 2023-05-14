/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iterator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:41:30 by ntan              #+#    #+#             */
/*   Updated: 2022/09/16 13:01:47 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../iterator.hpp"
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> myvector;
	for (int i=0; i<10; i++) myvector.push_back(i);

	typedef std::vector<int>::iterator iter_type;
															// ? 0 1 2 3 4 5 6 7 8 9 ?
	iter_type from (myvector.begin());                     //   ^
															//         ------>
	iter_type until (myvector.end());                      //                       ^
															//
	ft::iterator<iter_type> my_until (until);     // ^
															//         <------
	ft::iterator<iter_type> my_from (from);     //                     ^

	std::cout << "myvector:";
	// while (rev_from != rev_until)
	// 	std::cout << ' ' << *rev_from++;
	// std::cout << '\n';

	std::cout << from[1];
	std::cout << my_from[1];
	ft::iterator<iter_type> copy;
	for (copy = my_from;  copy != my_until; copy++)
		std::cout << *copy << std::endl;

	copy -= 2;
	std::cout << *copy;
	return 0;
}