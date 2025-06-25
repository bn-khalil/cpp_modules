/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:33:28 by kben-tou          #+#    #+#             */
/*   Updated: 2025/06/25 14:38:22 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string rep( std::string content, std::string s1,  std::string s2 ) {
    int         i;
    int         j;
    std::string new_content;

    i = 0;
    while ( content[i] ) {
        j = 0;
        while ( content[i + j] == s1[j] )
            j++;
        if ( s1[j] == '\0' ) {
            new_content.append( s2 );
            i += j;
        } else {
            new_content.append( 1, content[i] );
            i++;
        }
    }
    return ( new_content );
}

int main( int ac, char **av ) {

    std::string line;
    std::string content;

    if ( ac != 4 || std::string ( av[2] ).empty() )
        return ( std::cerr << "Invalid arguments!" << std::endl, 1);

    std::ifstream  inf( av[1] );
    if ( !inf.is_open() )
        return ( std::cout << "input file opening process failed!" << std::endl, 1 );

    while ( std::getline(inf, line) )
    {
        content.append( line );
        if ( !inf.eof() )
            content += "\n";
    }

    std::ofstream outf ( std::string( av[1] ) + ".replace" );
    if ( !inf.is_open() ) {
        inf.close();
        return ( std::cout << "output file opening process failed!" << std::endl, 1 );
    }

    outf << rep( content, av[2], av[3] );

    inf.close();
    outf.close();

    return ( 0 );
}