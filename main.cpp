/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:28:45 by ntan              #+#    #+#             */
/*   Updated: 2022/10/27 16:11:16 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 0
	#include <vector>
	#include <map>
	#include <stack>
	namespace ft = std;
#else
	#include "vector.hpp"
	#include "stack.hpp"
	#include "map.hpp"
#endif

#include <string>
#include <iostream>

int main()
{

	std::cout << "\n============================\n" << std::endl;
	std::cout << "\n============VECTOR==========\n" << std::endl;
	std::cout << "\n============================\n" << std::endl;

	std::cout << "\n===== CONSTRUCTORS =====\n" << std::endl;
	ft::vector<std::string>		ftvec;
	ft::vector<std::string>		ftvec2(100, "j'adore ft_containers");
	ft::vector<std::string>		ftvec3(ftvec2.begin(), ftvec2.begin() + 10);
	ft::vector<std::string>		ftvec4(ftvec3);
	ft::vector<std::string>		ftvec_copy = ftvec4;
	// ftvec.print("ftvec");
	// ftvec2.print("ftvec2");
	// ftvec3.print("ftvec3");
	// ftvec4.print("ftvec4");
	// ftvec_copy.print("ftvec_copy");

	std::cout << "\n===== CAPACITY =====\n" << std::endl;
	std::cout << "size : " << ftvec3.size() << std::endl;
	std::cout << "max_size : " << ftvec3.max_size() << std::endl;
	ftvec3.resize(15);
	std::cout << "after resize(15), size = : " << ftvec3.size() << std::endl;
	std::cout << "capacity = " << ftvec3.capacity() << std::endl;
	ftvec3.reserve(40);
	std::cout << "after reserve(40), capacity = " << ftvec3.capacity() << std::endl;
	std::cout << "ftvec3.empty() = " << ftvec3.empty() << std::endl;

	std::cout << "\n===== ELEMENT ACCESS =====\n" << std::endl;
	std::cout << "ftvec3[0] : " << ftvec3[0] << std::endl;
	std::cout << "using ftvec3[0] = je deteste ft_containers" << std::endl;
	ftvec3[0] = "je deteste ft_containers";
	std::cout << "ftvec3.at(0) = " << ftvec3.at(0) << std::endl;
	std::cout << "ftvec3.front() = " << ftvec3.front() << std::endl;
	std::cout << "using ftvec3.back() = j'adore xavier niel" << std::endl;
	ftvec3.back() = "j'adore xavier niel";
	std::cout << "ftvec3.back() = " << ftvec3.back() << std::endl;
	std::cout << "ftvec3.data() = " << ftvec3.data() << std::endl;

	std::cout << "\n===== ITERATORS =====\n" << std::endl;
	for (ft::vector<std::string>::iterator it = ftvec3.begin(); it != ftvec3.end(); it++)
		std::cout << "iterateur qui marche : " << *it << std::endl;
	
	std::cout << "\n===== MODIFIERS =====\n" << std::endl;
	ftvec3.insert(ftvec3.begin() + 1, "c quand l'afterwork");
	ftvec3.insert(ftvec3.begin() + 2, 3, "on veut des gnogno des kikis");
	ftvec3.insert(ftvec3.begin() + 10, ftvec3.begin(), ftvec3.begin() + 2);
	ftvec3.erase(ftvec3.begin());
	ftvec3.erase(ftvec3.begin() + 10, ftvec3.begin() + 13);

	std::cout << "\n===== CONST_ITERATORS =====\n" << std::endl;
	for (ft::vector<std::string>::const_iterator it = ftvec3.begin(); it != ftvec3.end(); it++)
		std::cout << "iterateur qui marche : " << *it << std::endl;
	
	ftvec3.push_back("le c++ c'est magique");
	ftvec3.push_back("miam miam");
	ftvec3.pop_back();
	
	std::cout << "\n===== REVERSE_ITERATORS =====\n" << std::endl;
	for (ft::vector<std::string>::reverse_iterator it = ftvec3.rbegin(); it != ftvec3.rend(); it++)
		std::cout << "reverse_iterateur qui marche : " << *it << std::endl;

	std::cout << "\n===== RELATIONAL OPERATORS =====\n" << std::endl;
	std::cout << "ftvec3 == ftvec2 : " << (ftvec3 == ftvec2) << std::endl;
	ftvec_copy = ftvec3;
	std::cout << "ftvec3 == ftvec_copy : " << (ftvec3 == ftvec_copy) << std::endl;

	
	std::cout << "\n============================\n" << std::endl;
	std::cout << "\n============STACK===========\n" << std::endl;
	std::cout << "\n============================\n" << std::endl;

	ft::stack<int>	ftstack;
	
	ftstack.push(12);
	ftstack.push(-21);
	ftstack.push(58);
	ftstack.push(7);
	
	ftstack.pop();
	ftstack.pop();

	std::cout << "ftstack.size() = " << ftstack.size() << std::endl;
	std::cout << "ftstack.top() = " << ftstack.top() << std::endl;

	std::cout << "\n============================\n" << std::endl;
	std::cout << "\n=============MAP============\n" << std::endl;
	std::cout << "\n============================\n" << std::endl;

	ft::map<int, std::string>	ftmap;
	ft::map<int, std::string>	ftmap1;
	ft::map<int, std::string>	ftmap_copy;

	for (int i = 0; i < 10; i++)
		ftmap[i + 200] = std::string(i, 49);
	ftmap1[1] = "salut";
	ftmap1[14] = "ca va ?";
	ftmap1[-2] = "ca gazouille";
	ftmap1[-39] = "petite petanque ?";
	ftmap1[42] = "meilleur nombre";
	ftmap1[21] = "on est la hein";
	ftmap1[59] = "59 l'heure de la teuf";
	ftmap1[24] = "24heures que je code jpp";
	ftmap1[8] = "8 x 8 = 64";
	ftmap1[9001] = "it's over nine thousand";
	ftmap1[-10] = "dark sasuke";
	ftmap1[92] = "92 departement Hauts de seine";
	ftmap1[101] = " 101 ans et toutes ses dents";
	ftmap1[-402000] = " le compte en banque Balkany";
	ftmap1[-1411] = " mon nombre d heure sur lol depuis la s11";
	ftmap1[123] = "soleil";
	ftmap1[68] = "et non pas celui d'apres";
	ftmap1[3] = "mon chiffre prefere";
	ftmap1[111111] = "un un un un un un un";

	std::cout << "\n===========CAPACITY===========\n" << std::endl;
	std::cout << "ftmap1.empty() = " << ftmap1.empty() << std::endl;
	std::cout << "ftmap1.size() = " << ftmap1.size() << std::endl;
	std::cout << "ftmap1.max_size() = " << ftmap1.max_size() << std::endl;

	std::cout << "\n===========ELEMENT ACCESS===========\n" << std::endl;	
	std::cout << "ftmap1[42] = " << ftmap1[42] << std::endl;
	std::cout << "ftmap.at(111111) = " << ftmap1.at(111111) << std::endl;

	std::cout << "\n===========MODIFIERS===========\n" << std::endl;
	ftmap1.insert(ft::make_pair(50, "et beh deja un demi siecle"));
	ftmap1.insert(ft::make_pair(360, "no scope tomahawk"));
	ftmap1.insert(ftmap.begin(), ftmap.end());

	std::cout << "ftmap.clear()" << std::endl;
	ftmap.clear();
	std::cout << "ftmap.empty()" << ftmap.empty() << std::endl;

	std::cout << "\n===========ITERATORS===========\n" << std::endl;
	for (ft::map<int, std::string>::iterator it = ftmap1.begin(); it != ftmap1.end(); it++)
		std::cout << (*it).first << " = "<< (*it).second << std::endl;

		
	std::cout << "\n===========OPERATIONS===========\n" << std::endl;	
	std::cout << "ftmap1.find(101) = " << (*ftmap1.find(101)).first << std::endl;
	std::cout << "ftmap1.find(777) = " << (*ftmap1.find(777)).first << std::endl;
	std::cout << "ftmap1.count(92) = " << ftmap1.count(92) << std::endl;
	std::cout << "ftmap1.count(777) = " << ftmap1.count(777) << std::endl;
	std::cout << "ftmap1.lower_bound(123) (>=) = " << (*ftmap1.lower_bound(123)).first << std::endl;
	std::cout << "ftmap1.upper_bound(123) (>) = " << (*ftmap1.upper_bound(123)).first << std::endl;

	std::cout << "\n===========RELATIONAL OP===========\n" << std::endl;
	std::cout << "ftmap1 == ftmap : " << (ftmap1 == ftmap) << std::endl;
	ftmap = ftmap1;
	std::cout << "ftmap1 == ftmap : " << (ftmap1 == ftmap) << std::endl;

	std::cout << "\n===========MODIFIERS===========\n" << std::endl;
	std::cout << "ftmap1.erase(ftmap1.find(200), ftmap1.find(209))" << std::endl;
	ftmap1.erase(ftmap1.find(200), ftmap1.find(209));

	std::cout << "\n===========REVERSE_ITERATORS===========\n" << std::endl;
	for (ft::map<int, std::string>::reverse_iterator it = ftmap1.rbegin(); it != ftmap1.rend(); it++)
		std::cout << (*it).first << " = "<< (*it).second << std::endl;

	// ftmap1.print2d();

	return (0);
	
	}


	
	// ft::map<int, std::string> ftvec;
	// ft::map<int, std::string> ftmap;

	// ftvec.insert(ft::make_pair(-10, "yo"));
	// ftvec.insert(ft::make_pair(61, "yaya"));
	// ftvec.insert(ft::make_pair(31, "ez"));
	// ftvec.treeInorder();

	// ftmap.insert(ft::make_pair(-60, "coco"));
	// ftmap.insert(ft::make_pair(-50, "coucou"));
	// ftmap.insert(ft::make_pair(12, "salut"));
	// ftmap.treeInorder();
	// ftmap.insert(ft::make_pair(-20, "t"));
	// ftmap.erase(++ftmap.begin());
	// std::cout << "erased = " << ftmap.erase(-21) << std::endl;
	// ftmap.insert(ft::make_pair(10, "v"));
	// ftmap.treeInorder();

	// std::cout << ftmap.size() << std::endl;
	// std::cout << ftmap.count(10) << std::endl;
	// std::cout << ftmap.count(8) << std::endl;

	// ftmap.swap(ftvec);
	// std::cout << "lower bound = " << (ftmap.lower_bound(-60)).base()->value << std::endl;
	// std::cout << "upper bound = " << (ftmap.upper_bound(-60)).base()->value << std::endl;
	// ftmap.treeInorder();

	// ft::map<char, int> fteqr;
	// fteqr['a'] = 10;
	// fteqr['b'] = 20;
	// fteqr['c'] = 30;

	// ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> ret;
	// ret = fteqr.equal_range('b');

	// std::cout << "lower bound points to: ";
	// std::cout << ret.first->first << " => " << ret.first->second << '\n';
	// std::cout << "upper bound points to: ";
	// std::cout << ret.second->first << " => " << ret.second->second << '\n';
	
	// ft::map<char, int> fteqr2(fteqr);
	// fteqr2['d'] = 45;
	// fteqr2.erase('a');
	// fteqr2.treeInorder();
	// fteqr.treeInorder();

	// ft::map<char, int> fteqr3(fteqr);
	// fteqr3 = fteqr2;
	// fteqr3.treeInorder();

	// ft::map<int, std::string> m1;
	// ft::map<int, std::string> m2;

	// std::cout << m1.empty() << std::endl;
	// std::cout << fteqr.empty() << std::endl;
	
	// std::vector< ft::pair<int, std::string> > list;
	// list.push_back(ft::make_pair(1, "coucou"));
	// list.push_back(ft::make_pair(2, "salut"));
	// list.push_back(ft::make_pair(3, "ca va"));
	// list.push_back(ft::make_pair(4, "hola"));
	// list.push_back(ft::make_pair(5, "como esta"));
	// list.push_back(ft::make_pair(6, "my"));
	// list.push_back(ft::make_pair(7, "llamo"));
	// list.push_back(ft::make_pair(8, "benito"));
	// for (int i = 1; i < 12; i++)
	// {
	// 	list.push_back(ft::make_pair(i, std::string(i, i + 65)));
	// }
	 
	// ft::map<int, std::string> mera(list.begin(), list.end());
	// mera.treeInorder();
	// mera.erase(mera.begin());
	// mera.treeInorder();
	// mera.erase(++mera.begin());
	// mera.treeInorder();
	// mera.erase(--mera.end());
	// mera.treeInorder();
	// mera.erase(++(++(++mera.begin())));
	// mera.treeInorder();
	
	// mera.erase(mera.begin(), ++mera.begin());
	// mera.treeInorder();

	// ft::map<int, std::string> mfc(list.begin(), list.end());

	// std::cout << *(mfc.find(1)) << std::endl;
	// std::cout << *(mfc.find(20)) << std::endl;
	// std::cout << *(mfc.find(-1)) << std::endl;
	// mfc.find(3)->second = "coucou";
	// mfc.treeInorder();

	// ft::map<int, std::string> mera2;

	// mera2[42] = "lol";
	// mera2[50] = "mdr";
	// mera2[25] = "funny";
	// mera2[46] = "bunny";
	// mera2[21] = "fizz";
	// mera2[30] = "buzz";
	// mera2[55] = "fuzzy";
	// mera2[18] = "bee";
	// mera2[23] = "coconut";
	// mera2[28] = "diary";
	// mera2[35] = "fiesta";
	// mera2[44] = "hello";
	// mera2[48] = "world";
	// mera2[53] = "this is a test";
	// mera2[80] = "hey";
	// mera2[12] = "no";
	// mera2[20] = "idea";
	// mera2[22] = "123";
	// mera2[24] = "345";
	// mera2[27] = "27";
	// mera2[29] = "29";
	// mera2[33] = "33";
	// mera2[38] = "38";
	// mera2[43] = "1";
	// mera2[45] = "2";
	// mera2[47] = "3";
	// mera2[49] = "4";
	// mera2[51] = "5";
	// mera2[54] = "6";
	// mera2[60] = "7";
	// mera2[90] = "8";

	// mera2.print2d();
	
	// mera2.erase(25);
	// mera2.erase(55);
	// mera2.erase(24);
	// mera2.erase(54);
	// mera2.print2d();
	// mera2.treeInorder();
	// mera2.erase(22);
	// mera2.print2d();
	// mera2.treeInorder();
	// mera2.erase(51);
	// mera2.print2d();
	// mera2.treeInorder();
	// mera2.erase(21);
	// mera2.print2d();
	// mera2.treeInorder();
	// mera2.erase(53);
	// mera2.print2d();
	// mera2.treeInorder();
	// mera2.erase(20);
	// mera2.print2d();
	// mera2.treeInorder();
	// mera2.erase(23);
	// mera2.print2d();
	// mera2.treeInorder();

	// std::map<int, std::string>	stdhello;

	// for (int i = 1 ; i < 40; i++)
	// {
	// 	stdhello.insert(std::make_pair(i, std::string(i % 10, i + 64)));
	// }

	// std::map<int, std::string>::iterator nbeg = stdhello.begin();
	// std::map<int, std::string>::iterator nend = nbeg;
	// std::advance(nbeg, 24);
	// std::advance(nend, 30);
	// stdhello.erase(nbeg, nend);
	
	// std::map<int, std::string>::iterator beg = stdhello.begin();
	// std::map<int, std::string>::iterator end = stdhello.end();
	// while (beg != end)
	// {
	// 	std::cout << (*beg).first << std::endl;
	// 	beg++;
	// }

	// ft::map<int, std::string>	hello;

	// for (int i = 1 ; i < 40; i++)
	// {
	// 	hello.insert(ft::make_pair(i, std::string(i % 10, i + 64)));
	// }

	// ft::map<int, std::string>::iterator mbeg = hello.begin();
	// ft::map<int, std::string>::iterator mend = mbeg;
	// std::advance(mbeg, 24);
	// std::advance(mend, 30);
	// hello.erase(mbeg, mend);


	// ft::map<int, std::string>::iterator beg1 = hello.begin();
	// ft::map<int, std::string>::iterator end1 = hello.end();
	// while (beg1 != end1)
	// {
	// 	std::cout << (*beg1).first << std::endl;
	// 	beg1++;
	// }

	// ft::map<int, char>	intcharmap;
	
	// for (int i = 0; i < 25; i++)
	// 	intcharmap.insert(ft::make_pair(i, i + 64));
	// // intcharmap.treeInorder();
	// // intcharmap.erase(intcharmap.begin(), intcharmap.end());
	// intcharmap.treeInorder();
	// intcharmap.insert(ft::make_pair(1, 'a'));
	// intcharmap[177] = 'g';
	// intcharmap.treeInorder();

	// ft::map<int, char> copy(intcharmap);
	
	// copy.treeInorder();

	// copy[45] = 'a';
	// copy.erase(20);
	// copy.treeInorder();
	// intcharmap.treeInorder();

	// copy = intcharmap;
	// copy.treeInorder();

	// copy.lower_bound(20);
	// copy.lower_bound(100);
	// copy.lower_bound(180);
	// copy.lower_bound(-2);

	// copy.upper_bound(20);
	// copy.upper_bound(100);
	// copy.upper_bound(180);
	// copy.upper_bound(-2);

	// ft::map<int, std::string> mera2;

	// mera2[42] = "lol";
	// mera2[50] = "mdr";
	// mera2[25] = "funny";
	// mera2[46] = "bunny";
	// mera2[21] = "fizz";
	// mera2[30] = "buzz";
	// mera2[55] = "fuzzy";
	// mera2[18] = "bee";
	// mera2[23] = "coconut";
	// mera2[28] = "diary";
	// mera2[35] = "fiesta";
	// mera2[44] = "hello";
	// mera2[48] = "world";
	// mera2[53] = "this is a test";
	// mera2[80] = "hey";
	// mera2[12] = "no";
	// mera2[20] = "idea";
	// mera2[22] = "123";
	// mera2[24] = "345";
	// mera2[27] = "27";
	// mera2[29] = "29";
	// mera2[33] = "33";
	// mera2[38] = "38";
	// mera2[43] = "1";
	// mera2[45] = "2";
	// mera2[47] = "3";
	// mera2[49] = "4";
	// mera2[51] = "5";
	// mera2[54] = "6";
	// mera2[60] = "7";
	// mera2[90] = "8";
	
	// mera2.print2d();
	// mera2.treeInorder();
	
	// ft::map<int, std::string>::iterator be = mera2.begin();
	// ft::map<int, std::string>::iterator en = be;
	
	// std::advance(be, 10);
	// std::advance(en, 15);
	// mera2.erase(be, en);
	// // mera2.erase(29);
	// // mera2.erase(30);
	// // mera2.erase(33);
	// // mera2.erase(35);
	// // mera2.erase(38);
	// // mera2.erase(42);

	// mera2.treeInorder();

	// mera2.insert(mera2.end(), ft::make_pair(95, "salutations"));
// 	return (0);
// }

// #define TESTED_NAMESPACE ft
// #define TESTED_TYPE		 char

// int main(void)
// {
// 	ft::vector<TESTED_TYPE> vct;
// 	ft::vector<TESTED_TYPE> vct_max(vct.max_size() + 1);

// 	vct.assign(0, 'c');
// 	vct.assign(10, 'a');
// 	vct.assign(5, 'b');
// 	// std::cout << vct.at(5) << std::endl;
// 	std::cout << (vct.max_size() ) << std::endl;
// 	std::cout << (vct.max_size() + 1) << std::endl;
// 	// vct.print("salut");
// 	return (0);
// }

// int		main(void)
// {
// 	const int size = 5;
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it = vct.rbegin();
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator ite = vct.rbegin();

// 	for (int i = 0; i < size; ++i)
// 		it[i] = (size - i) * 5;

// 	it = it + 5;
// 	it = 1 + it;
// 	it = it - 4;
// 	std::cout << *(it += 2) << std::endl;
// 	std::cout << *(it -= 1) << std::endl;

// 	*(it -= 2) = 42;
// 	*(it += 2) = 21;

// 	std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

// 	std::cout << "(it == const_it): " << (ite == it) << std::endl;
// 	std::cout << "(const_ite - it): " << (ite - it) << std::endl;
// 	std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

// 	// printSize(vct, true);
// 	return (0);
// }


// int		main(void)
// {
// 	const int size = 5;
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it_ = vct.begin();
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it(it_);

// 	for (int i = 0; i < size; ++i)
// 		vct[i] = (i + 1) * 5;
// 	vct.print();

// 	std::cout << (it_ == it.base()) << std::endl;
// 	std::cout << (it_ == (it + 3).base()) << std::endl;

// 	std::cout << *(it.base() + 1) << std::endl;
// 	std::cout << *(it - 3) << std::endl;
// 	std::cout << *(it - 3).base() << std::endl;
// 	it -= 3;
// 	std::cout << *it.base() << std::endl;

// 	std::cout << "TEST OFFSET" << std::endl;
// 	std::cout << *(it) << std::endl;
// 	std::cout << *(it).base() << std::endl;
// 	std::cout << *(it - 0) << std::endl;
// 	std::cout << *(it - 0).base() << std::endl;
// 	std::cout << *(it - 1).base() << std::endl;

// 	return (0);
// }

// int		main(void)
// {
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(10);
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct3;

// 	for (unsigned long int i = 0; i < vct.size(); ++i)
// 		vct[i] = (vct.size() - i) * 3;
// 	printSize(vct);

// 	vct2.insert(vct2.end(), 42);
// 	vct2.insert(vct2.begin(), 2, 21);
// 	printSize(vct2);

// 	vct2.insert(vct2.end() - 2, 42);
// 	printSize(vct2);

// 	vct2.insert(vct2.end(), 2, 84);
// 	printSize(vct2);

// 	vct2.resize(4);
// 	printSize(vct2);

// 	vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
// 	vct.clear();
// 	printSize(vct2);

// 	printSize(vct);

// 	for (int i = 0; i < 5; ++i)
// 		vct3.insert(vct3.end(), i);
// 	vct3.insert(vct3.begin() + 1, 2, 111);
// 	printSize(vct3);

// 	return (0);
// }


// int main()
// {
// 	std::vector<int> std_vector;
// 	ft::vector<int> test;
// 	ft::vector<int> test2;
// 	ft::vector<int> assign_test;

// 	// test.reserve(1);
// 	std::cout << "size : " << test.size() << std::endl;
// 	std::cout << "max_size : " << test.max_size() << std::endl;
// 	std::cout << "capacity : " << test.capacity() << std::endl;

// 	test.push_back(1);
// 	test.push_back(321);
	
// 	std::cout << test[1] << std::endl;
// 	test.pop_back();
// 	std::cout << "size : " << test.size() << std::endl;
// 	test.print();

// 	int i = 0;
// 	while (i < 1)
// 	{
// 		test.insert(test.begin(), 5);
// 		i++;
// 	}
// 	// print_vec_string(test);
// 	std::cout << "size : " << test.size() << std::endl;
// 	std::cout << "max_size : " << test.max_size() << std::endl;
// 	std::cout << "capacity : " << test.capacity() << std::endl;

// 	test.insert(test.begin(), 1, 2);
// 	test.print();

// 	test2.reserve(10);
// 	test2.insert(test2.begin(), test.begin(), test.end());
// 	test2.print();

// 	test2.push_back(42);
// 	test2.push_back(48);
// 	test2.print();
// 	std::cout << *(test2.erase(test2.begin())) << std::endl;
// 	std::cout << "CLEAR" << std::endl;
// 	test2.print();

// 	assign_test.assign(test2.begin(), test2.end());
// 	std::cout << "== test " << (test2 == assign_test) << std::endl;
// 	test2[0] = 777;
// 	test2.print();
// 	assign_test.print();

// 	test2.swap(assign_test);
// 	test2.print();
// 	assign_test.print();


// 	ft::vector<int>		salut(5, 10);
// 	ft::vector<int>		salut_copy(salut);
// 	ft::vector<int>		salut_equal;
// 	salut_equal = salut;

// 	salut.print();
// 	salut_copy.print();
// 	salut_equal.print();

// 	std::cout << "CLEAR" << std::endl;
// 	salut.clear();
// 	salut.print();
// 	salut_copy.print();
// 	salut_equal.print();
// 	// std::cout << salut.at(10) << std::endl;
// 	return (0);
// }

// int main()
// {
// 	ft::vector<std::string> vec;
// 	vec.push_back("AAAAA");
// 	vec.push_back("BBB");
// 	vec.push_back("CCCCCC");
// 	vec.push_back("DDDDDDDD");
// 	vec.push_back("EEEEEEEEEE");

// 	vec.print();
// 	vec.erase(vec.begin(), vec.begin() + 3);
// 	vec.print();
// 	return (0);
// }