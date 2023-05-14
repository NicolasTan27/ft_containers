/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_reverse_iterator.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:05:03 by ntan              #+#    #+#             */
/*   Updated: 2022/09/16 12:37:50 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../reverse_iterator.hpp"
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
	ft::reverse_iterator<iter_type> rev_until (from);     // ^
															//         <------
	ft::reverse_iterator<iter_type> rev_from (until);     //                     ^

	std::cout << "myvector:";
	while (rev_from != rev_until)
		std::cout << ' ' << *rev_from++;
	std::cout << '\n';

	return 0;
}