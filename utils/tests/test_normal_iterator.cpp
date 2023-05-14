/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_normal_iterator.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:14:17 by ntan              #+#    #+#             */
/*   Updated: 2022/09/16 13:58:02 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../normal_iterator.hpp"
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
	ft::normal_iterator<iter_type> my_until (until);     // ^
															//         <------
	ft::normal_iterator<iter_type> my_from (from);     //                     ^

	std::cout << my_from[1];
	my_from += 3;
	std::cout << *my_from;
	// std::cout << "myvector:";
	// while (rev_from != rev_until)
	// 	std::cout << ' ' << *rev_from++;
	// std::cout << '\n';

	// std::vector<int> numbers;
	// for (int i=0; i<10; i++) numbers.push_back(i);

	// ft::normal_iterator<std::vector> from(numbers);
	// ft::normal_iterator<std::vector> until(numbers+10);
	// for (; from != until; from++)
	// std::cout << *from << ' ';
	// std::cout << '\n';
	
	// return (0);
}