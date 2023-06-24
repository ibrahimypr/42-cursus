/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:35:27 by iyapar            #+#    #+#             */
/*   Updated: 2023/01/16 11:35:28 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include "iostream"

template<typename T> void iter(T *array, size_t len, void(*f)(T const &)){
    for (size_t i = 0; i < len; i++)
        f(array[i]);
}

#endif
