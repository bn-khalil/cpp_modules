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
        
void Span::addNumber( int n ) {
    if (this->n == this->ints.size())
        throw collectionFullException();
    this->ints.push_back(n);
}

// void Span::addNumber( std::vector<int>::iterator b, std::vector<int>::iterator e) {
//     if ((std::distance(b, e) + this->ints.size()) > this->n)
//         throw collectionFullException();
//     this->ints.insert(this->ints.end(), b, e);
// }

void Span::addNumber( std::vector<int>vec ) {
    if (vec.size() + this->ints.size() > this->n)
        throw collectionFullException();
    this->ints.insert(this->ints.end(), vec.begin(), vec.end());
}

size_t Span::shortestSpan() {
    return 1;
}

size_t Span::longestSpan() {
    return *std::max_element(this->ints.begin(), this->ints.end()) - *std::min_element(this->ints.begin(), this->ints.end());
}