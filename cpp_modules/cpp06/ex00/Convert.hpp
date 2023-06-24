/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:53:28 by iyapar            #+#    #+#             */
/*   Updated: 2023/01/13 15:53:28 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <string>
#include <cctype> // isprint
#include <sstream> // ostringstream
#include <climits> // int max min kontrol
#include <stdlib.h> // atoi atol

void conversionall(std::string str);
bool isOk(std::string &str);

#endif