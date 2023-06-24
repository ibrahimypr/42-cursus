/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:53:59 by iyapar            #+#    #+#             */
/*   Updated: 2023/01/13 16:45:12 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <iostream>

// uintptr_t C++ dilinde bir tamsayı veri tipidir. Bu veri tipi, bir işaretçi değerinin tam sayıya dönüştürülmüş hali olarak kullanılır.

int main()
{
    Data data;

    data.name = "Ferhat";
    data.department = "Security";
    data.job = "Guard";
    data.age = 25;
    data.isActive = true;

	std::cout << "Name: " << data.name << std::endl;
	std::cout << "Department: " << data.department << std::endl;
	std::cout << "Job: " << data.job << std::endl;
	std::cout << "Age: " << data.age << std::endl;
	std::cout << "IsActive: " << data.isActive << std::endl;

    std::cout << std::endl << std::endl;
    uintptr_t	serialize_input = serialize(&data);
	Data*		deserialize_output = deserialize(serialize_input);

    std::cout << "Name: " << deserialize_output->name << std::endl;
	std::cout << "Department: " << deserialize_output->department << std::endl;
	std::cout << "Job: " << deserialize_output->job << std::endl;
	std::cout << "Age: " << deserialize_output->age << std::endl;
	std::cout << "IsActive: " << deserialize_output->isActive << std::endl;
}