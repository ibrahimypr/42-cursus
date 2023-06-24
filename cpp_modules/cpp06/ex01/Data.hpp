/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:53:56 by iyapar            #+#    #+#             */
/*   Updated: 2023/01/13 15:53:57 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>

typedef struct 
{
    std::string name;
    std::string department;
    std::string job;
    int age;
    bool isActive;
} Data;

uintptr_t serialize(Data* data);
Data* deserialize(uintptr_t raw);

#endif