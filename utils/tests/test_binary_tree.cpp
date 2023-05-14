/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_binary_tree.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:52:22 by ntan              #+#    #+#             */
/*   Updated: 2022/10/08 01:36:45 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../binary_tree.hpp"
#include "../pair.hpp"
#include <string>

int main()
{
	// ft::Binary_tree<int>	test;

	// std::cout << test.insertNode(40) << std::endl;
    // std::cout << test.insertNode(30) << std::endl;
    // std::cout << test.insertNode(50) << std::endl;
    // std::cout << test.insertNode(15) << std::endl;
    // std::cout << test.insertNode(20) << std::endl;
    // std::cout << test.insertNode(10) << std::endl;
    // std::cout << test.insertNode(40) << std::endl;
    // std::cout << test.insertNode(60) << std::endl;

	// std::cout << test.searchNode(10) << std::endl;

	// test.del(10);
		
	// test.inorder(test.get_root());


	typedef		ft::pair<char,int>		charint;
	ft::Binary_tree<charint>	testpair;
	charint   	pairtest('a', 1);

	testpair.insertNode(pairtest);
	testpair.insertNode(ft::make_pair('c', 2));
	testpair.insertNode(ft::make_pair('b', 3));
	testpair.insertNode(ft::make_pair('e', 4));

	testpair.inorder(testpair.get_root());

	ft::Binary_tree<charint>::iterator mbegin(testpair.begin());
	ft::Binary_tree<charint>::iterator mend(testpair.end());
	
	// testpair.del(ft::make_pair('b', 3));
	
	while (mbegin != mend)
	{
		std::cout << *mbegin << std::endl;
		mbegin++;
	}

	std::cout << testpair.size(testpair.get_root()) << std::endl;

	return (0);
}