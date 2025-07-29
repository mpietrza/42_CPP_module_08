/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:32:30 by mpietrza          #+#    #+#             */
/*   Updated: 2025/07/29 14:16:25 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <vector>
#include <list>
#include <deque>

template <typename T>
static void printContainer(const T& container) {
	std::cout << "{";
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
		std::cout << *it;
		typename T::const_iterator next = it;
		++next;
		if (next != container.end())
			std::cout << ", ";
		else
			std::cout << "}";
	}
}

int main(void) {
	int val = 4;

//--------------------vector--------------------------//
	std::vector<int> v;
	for (int i = 0; i <= 3; ++i)
		v.push_back(i * 2);
	v.push_back(4);

	std::cout << "\nUsing easyfind to find the first occurrence of <int> '" << val << "' in the vector array of integers ";
	printContainer(v);
	std::cout << std::endl;

	try {
		std::vector<int>::iterator it = easyfind(v, val);
		int pos = std::distance(v.begin(), it) + 1;

		std::cout << "Easyfind found the first occurrence of <int> " << *it << " on the positon " << pos << "." << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	val = 5;
	std::cout << "\nUsing easyfind to find the first occurrence of <int> '" << val << "' in the vector array of integers ";
	printContainer(v);
	std::cout << std::endl;

	try {
		std::vector<int>::iterator it = easyfind(v, val);
		int pos = std::distance(v.begin(), it) + 1;

		std::cout << "Easyfind found the first occurrence of <int> " << *it << " on the positon " << pos << "." << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

//--------------------list--------------------------//
	std::list<int> l;
	for (int i = -15; i <= 15; ++i)
		l.push_back(i % 5);
	
	val = 3;
	std::cout << "\nUsing easyfind to find the first occurrence of <int> '" << val << "' in the list of integers ";
	printContainer(l);
	std::cout << std::endl;

	try {
		std::list<int>::iterator it = easyfind(l, val);
		int pos = std::distance(l.begin(), it) + 1;

		std::cout << "Easyfind found the first occurrence of <int> " << *it << " on the position " << pos << "." << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
//--------------------deque (double-ended queue)--------------------------//
	std::deque<int> d;
	d.push_back(1);
	d.push_front(0);
	d.push_back(-20);
	d.push_front(1);
	d.push_back(1);
	d.push_front(0);
	
	val = 1;
	std::cout << "\nUsing easyfind to find the first occurrence of <int> '" << val << "' in the double-ended queue of integers ";
	printContainer(d);
	std::cout << std::endl;

	try {
		std::deque<int>::iterator it = easyfind(d, val);
		int pos = std::distance(d.begin(), it) + 1;

		std::cout << "Easyfind found the first occurrence of <int> " << *it << " on the position " << pos << "." << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

}



