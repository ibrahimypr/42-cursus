/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:35:29 by iyapar            #+#    #+#             */
/*   Updated: 2023/01/16 11:35:30 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void    print_number(const int &n){
    std::cout << n << "	";
}

void	square_of_number_print(const int &n){
	std::cout << (n * n) << "	";
}

void print_string(const std::string &s){
    std::cout << s + "	";
}

void	upper_print(const std::string &s)
{
	for (int i = 0 ; i < s.size() ; i++){
		char c = s[i];
		if (c >= 'a' && c <= 'z')
			c -= 32;
		std::cout << c;
	}
	std::cout << "	";
}

int main()
{
	std::cout << "Test 1" << std::endl;
    int array[5] = {4, 12, 3, 5, 1};
    iter(array, 5, print_number);
    std::cout << std::endl;
    iter(array, 5, square_of_number_print);
    std::cout << std::endl;
	
    std::cout << std::endl;
	std::cout << "Test 2" << std::endl;
    std::string arr[2] = {"Kuzey", "Guney"};
    iter(arr, 2, print_string);
    std::cout << std::endl;
    iter(arr, 2, upper_print);
    std::cout << std::endl;
}
