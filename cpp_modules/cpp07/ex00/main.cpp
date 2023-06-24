/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:35:16 by iyapar            #+#    #+#             */
/*   Updated: 2023/01/16 11:35:17 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <string>

int main(void)
{
	int n1 = 10;
	int n2 = 20;

	::swap(n1, n2);
	std::cout << "n1 = " << n1 << std::endl << "n2 = " << n2 << std::endl;
	std::cout << "min(n1, n2) = " << ::min(n1, n2) << std::endl;
	std::cout << "max(n1, n2) = " << ::max(n1, n2) << std::endl << std::endl;

	std::string s1 = "string1";
	std::string s2 = "string2";

	::swap(s1, s2);
	std::cout << "s1 = " << s1 << std::endl << "s2 = " << s2 << std::endl;
	std::cout << "min(s1, s2) = " << ::min(s1, s2) << std::endl;
	std::cout << "max(s1, s2) = " << ::max(s1, s2) << std::endl;
}
