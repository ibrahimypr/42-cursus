/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:53:32 by iyapar            #+#    #+#             */
/*   Updated: 2023/01/13 15:53:32 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cout << "Usage: ./convert <scalar_to_convert>\n"
			"Valid scalars to convert: int, float, double or char."
			    << std::endl;
        return(1);
    }
    std::cout << "I am trying to convert your " << av[1] << std::endl;
    std::string str = (std::string)av[1];
    if(isOk(str))
        conversionall(str);
}