#include "SampleClass.hpp"
#include <iostream>
#include <string>


Sample::Sample()
{
	std::cout << "Constructor called" << std::endl;
	return ;
}

Sample::~Sample(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

void Sample::setFirstName(std::string first)
{
	this->firstName = first;
}
