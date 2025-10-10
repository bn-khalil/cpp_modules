/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:59:29 by kben-tou          #+#    #+#             */
/*   Updated: 2025/10/08 13:46:06 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( unsigned int n ): n(n) {
    std::cout << "Span Default constructor called!" << std::endl;
}

Span::Span( const Span& other ):ints(other.ints), n( other.n ) {
    std::cout << "Copy Span constructor called!" << std::endl;
}

Span & Span::operator = ( Span &other ) {
    std::cout << "Copy Span assinement operator called!" << std::endl;
    if (this != &other) {
        this->n = other.n;
        this->ints = other.ints;
    }
    return ( *this );
}

Span::~Span() {
    std::cout << "Span Destructor called!" << std::endl;
}

const char *Span::collectionFullException::what() const throw() {
        return "can't add new item";
}

const char *Span::shortSpanException::what() const throw() {
        return "not Enough items in collection";
}
        
void Span::addNumber( int n ) {
    if (this->n == this->ints.size())
        throw collectionFullException();
    this->ints.push_back(n);
}

void Span::addNumber( std::vector<int>& vec ) {
    if (vec.size() + this->ints.size() > this->n)
        throw collectionFullException();
    this->ints.insert(this->ints.end(), vec.begin(), vec.end());
}

size_t Span::shortestSpan() {

    if (this->ints.size() < 2)
        throw shortSpanException();

    std::vector<int> tmp = this->ints;
    std::sort(tmp.begin(), tmp.end());

    int shortest = INT_MAX;

    for(size_t i = 0;i < tmp.size() - 1; i++) {
        if (i + 1 <= tmp.size()) {
            int res = tmp[i + 1] - tmp[i];
            if (res < shortest)
                shortest = res;
        }
    }
    return static_cast<size_t>(shortest);
}

size_t Span::longestSpan() {
    int maxints = *std::max_element(this->ints.begin(), this->ints.end());
    int minints = *std::min_element(this->ints.begin(), this->ints.end());
    return maxints - minints;
}

void Span::displayCollection() {
    for(size_t ele = 0;ele < this->ints.size(); ele++) {
        std::cout << this->ints.at(ele) << std::endl;
    }
}