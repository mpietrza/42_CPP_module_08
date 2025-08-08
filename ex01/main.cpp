/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:52:46 by mpietrza          #+#    #+#             */
/*   Updated: 2025/08/08 16:07:16 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <cstdlib> // rand, srand
#include <ctime>   // time
//#include <string> 
#include <cstdlib> // strtoul, atoi
#include <climits> // 
#include <vector>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Type only the number of numbers you want - value in the int range." << std::endl
				  << "It will be the count of random numbers to check the span." << std::endl;
		return 0;
	}

	unsigned long rangeLong = strtoul(argv[1], NULL, 10);
	if (rangeLong < 2 || rangeLong > ULONG_MAX) {
		std::cerr << "Type a number greater then 1 in the unsigned int range." << std::endl
				  << "There must be at least 2 numbers in the range to check the span." << std::endl;
		return 0;
	}
	unsigned int range = static_cast<unsigned int>(rangeLong);
	
	Span span(range);

	std::vector<int> randoms;
	srand(time(0));
	for (unsigned int i = 0; i < range; ++i) {
		int number = rand();
		randoms.push_back(number);
	}

	if (range <= 10000) {
		std::cout << "The random numbers in the given quantity are:" << std::endl;
		for (unsigned int i = 0; i < randoms.size(); ++i) {
			std::cout << randoms[i];
			if ((i + 1) % 10 == 0)
				std::cout << std::endl;
			else
				std::cout << " ";
		}
	} else {
		std::cout << "Too many numbers to display." << std::endl
				  << "The span will be calculated without printing the numbers." << std::endl;
	}

	// Use addNumbers to fill the Span
	span.addNumbers(randoms.begin(), randoms.end());

	std::cout << std::endl;
	try {
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span:  " << span.longestSpan() << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
