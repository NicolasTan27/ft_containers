/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rb_tree.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:41:15 by ntan              #+#    #+#             */
/*   Updated: 2022/09/28 15:57:01 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../rbtree.hpp"

int main() 
{
ft::RBTree tree;

tree.insert(7);
tree.insert(3);
tree.insert(18);
tree.insert(10);
tree.insert(22);
tree.insert(8);
tree.insert(11);
tree.insert(26);
tree.insert(2);
tree.insert(6);
tree.insert(13);

tree.printInOrder();
tree.printLevelOrder();

std::cout << std::endl <<"Deleting 18, 11, 3, 10, 22"<< std::endl;

tree.deleteByVal(18);
tree.deleteByVal(11);
tree.deleteByVal(3);
tree.deleteByVal(10);
tree.deleteByVal(22);

tree.printInOrder();
tree.printLevelOrder();
return 0;
}
