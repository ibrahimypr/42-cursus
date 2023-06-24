/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:35:32 by iyapar            #+#    #+#             */
/*   Updated: 2023/01/16 12:12:43 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>


template <class T>class Array
{
private :
	int _size;
	T* _arr;
public :
	Array() : _size(0), _arr(new T[0]) {}
	Array(unsigned int n) : _size(n), _arr(new T[n])
	{
		for (int i = 0 ; i < _size; i++)
			_arr[i] = 0;
	}
	Array(const Array& a) : _size(a._size), _arr(new T[a._size])
	{
		for (int i = 0 ; i < _size ; i++)
			_arr[i] = a[i];
	}
	~Array()
	{
		delete[] _arr;
		_arr = NULL;
	}
	Array& operator=(const Array& a)
	{
		if (this != &a)	
		{
			delete[] _arr;
			_arr = NULL;
			_size = a._size;
			_arr = new T[_size];
			for (int i = 0 ; i < _size ; i++)
				_arr[i] = a[i];
		}
		return *this;
	}
	T& operator[](int idx)
	{
		if (idx < 0 || idx >= _size)
			throw OutOfBoundException();
		return _arr[idx];
	}
	
	const T& operator[](int idx) const
	{
		if (idx < 0 || idx >= _size)
			throw Array::OutOfBoundException();
		return _arr[idx];
	}
	size_t size() const
	{
		return (this->_size);
	}

	
	class OutOfBoundException : public std::exception
	{
	public:
		const char* what(void) const throw()
		{
			return "Out of Bounds";
		}
	};
};

#endif
