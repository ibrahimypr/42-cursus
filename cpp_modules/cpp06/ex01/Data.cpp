/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:53:53 by iyapar            #+#    #+#             */
/*   Updated: 2023/01/13 16:46:31 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// reinterpret_cast C++ dilinde bir tür dönüştürme operatörüdür. Bu operatör, verinin bit düzeyinde yeniden yorumlanmasını sağlar. 
// bir işaretçi değerinin tam sayıya dönüştürülmüş hali olarak kullanılması gerektiğinde ya da bir verinin başka bir veri tipine dönüştürülmesi gerektiğinde reinterpret_cast operatörü kullanılır.

#include "Data.hpp"

uintptr_t serialize(Data* data) // Bu fonksiyon, verilen Data* data işaretçisini uintptr_t tipine dönüştürür. Bu işlem, işaretçinin memory adresini tam sayıya dönüştürür. (pointer to int)
{
    return reinterpret_cast<uintptr_t>(data);
}

Data* deserialize(uintptr_t raw) // Bu işlem, uintptr_t veri tipinde saklanan memory adresini tekrar Data* işaretçi tipine dönüştürür. (int to pointer)
{
    return reinterpret_cast<Data *>(raw);
}