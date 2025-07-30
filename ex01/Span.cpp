/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:29:46 by mpietrza          #+#    #+#             */
/*   Updated: 2025/07/30 16:50:44 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0) {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span &other) : _n(other._n), _numbers(other._numbers) {}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		_n = other._n;
		_numbers = other._numbers;
	}
	return (*this);
}

Span::~Span() {
	// No need to manually clear the vector; std::vector's destructor handles it.
}

void Span::addNumber(int number) {
	if (_numbers.size() >= _n)
		throw std::runtime_error("Numbers container is full!");
	_numbers.push_back(number);
}

unsigned int Span::shortestSpan() {
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span!");
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	int minSpan = sorted[1] - sorted[0];
	for (unsigned int i = 1; i < sorted.size() - 1; ++i) {
		int span = sorted[i + 1] - sorted[i];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

unsigned int Span::longestSpan() {
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span!");
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());
	return max - min;
}

