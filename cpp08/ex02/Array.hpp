/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:28:05 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/06 10:45:10 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "external.hpp"

template <typename T>
class Array
{
  public:
	Array(void)
		: _arr_len(0), _content(NULL)
	{
		std::cout << "Default Constructor: Array of size " << _arr_len << " constructed" << std::endl;
	}

	Array(unsigned int size)
		: _arr_len(size), _content(NULL)
	{
		std::cout << "Size Constructor: Array of size " << _arr_len << " constructed" << std::endl;
		if (size > 0)
		{
			this->_content = new T[size]();
		}
	}

	Array(const Array &other)
		: _arr_len(other.size()), _content(NULL)
	{
		std::cout << "Copy Constructor: Array of size " << _arr_len << " constructed" << std::endl;
		if (this->_arr_len > 0)
		{
			this->_content = new T[this->_arr_len]();
			for (unsigned int i = 0; i < this->_arr_len; i++)
			{
				this->_content[i] = other._content[i];
			}
		}
	}

	Array &operator=(const Array &other)
	{
		if (this != &other)
		{
			delete[] this->_content;
			this->_content = NULL;
			this->_arr_len = other.size();
			if (this->_arr_len > 0)
			{
				this->_content = new T[this->_arr_len]();
				for (unsigned int i = 0; i < this->_arr_len; i++)
				{
					this->_content[i] = other._content[i];
				}
			}
		}
		return (*this);
	}

	virtual ~Array(void)
	{
		delete[] this->_content;
		this->_content = NULL;
		std::cout << "Array destroyed" << std::endl;
	}

	unsigned int size(void) const
	{
		return (this->_arr_len);
	}

	T &operator[](unsigned int index)
	{
		if (index >= this->size())
		{
			throw std::out_of_range("Index out of bounds");
		}
		return (this->_content[index]);
	}

	const T &operator[](unsigned int index) const
	{
		if (index >= this->size())
		{
			throw std::out_of_range("Index out of bounds");
		}
		return (this->_content[index]);
	}

  private:
	unsigned int _arr_len;
	T *_content;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, Array<T> const &arr)
{
	if (arr.size() == 0)
	{
		os << std::endl;
		os << ">>Empty Array<<";
		os << std::endl;
		os << std::endl;
	}
	else
	{
		os << "[" << std::endl;
		for (unsigned int i = 0; i < arr.size(); i++)
		{
			os << "  [ ";
			os << i << ": ";
			os << arr[i];
			os << " ]";
			os << std::endl;
		}
		os << "]";
		os << std::endl;
		os << std::endl;
	}
	return (os);
}