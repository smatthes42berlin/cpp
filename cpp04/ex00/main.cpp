/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:30:21 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/30 16:21:29 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "external.hpp"
#include "main.hpp"

int	main(void)
{
	testsDefaultFunctionality();
	testsFromSubject();
	testWrongClasses();
	return (0);
}

void	testsDefaultFunctionality(void)
{

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "***Tests default functionality***";
	std::cout << std::endl;
	std::cout << std::endl;

	Animal	*A1;
	Animal	*A2;
	Cat		*C1;
	Cat		*C2;
	Dog		*D1;
	Dog		*D2;

	std::cout << "1";
	A1 = new Animal();
	std::cout << std::endl << "2";
	A2 = new Animal(*A1);
	std::cout << std::endl << "3";
	C1 = new Cat();
	std::cout << std::endl << "4";
	C2 = new Cat(*C1);
	std::cout << std::endl << "5";
	D1 = new Dog();
	std::cout << std::endl << "6";
	D2 = new Dog(*D1);
	std::cout << std::endl << "7";

	
	*A2 = *A1;
	std::cout << std::endl << "8";
	*C2 = *C1;
	std::cout << std::endl << "9";
	*D2 = *D1;
	std::cout << std::endl << "10";
	A1->makeSound();
	std::cout << std::endl << "11";
	C1->makeSound();
	std::cout << std::endl << "12";
	D1->makeSound();

	delete A1;
	std::cout << std::endl << "13";
	delete A2;
	std::cout << std::endl << "14";
	delete C1;
	std::cout << std::endl << "15";
	delete C2;
	std::cout << std::endl << "16";
	delete D1;
	std::cout << std::endl << "17";
	delete D2;
	std::cout << std::endl;
}

void	testsFromSubject(void)
{

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "***Tests from subject***";
	std::cout << std::endl;
	std::cout << "***makeSound should call implementation of derived class***";
	std::cout << std::endl;
	std::cout << "***derived class destructor should get called first, then base class***";
	std::cout << std::endl;
	std::cout << std::endl;

	const Animal	*meta = new Animal();
	std::cout << std::endl;
	const Animal	*j = new Dog();
	std::cout << std::endl;
	const Animal	*i = new Cat();
	std::cout << std::endl;
	
	std::cout << j->get_type() << " " << std::endl;
	std::cout << i->get_type() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete			meta;
	delete			j;
	delete			i;
}

void	testWrongClasses(void)
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "***Test wrong classes***";
	std::cout << std::endl;
	std::cout << "***makeSound method of base class gets called***";
	std::cout << std::endl;
	std::cout << "***derived class destructor doesn't get called first***";
	std::cout << std::endl;
	std::cout << std::endl;

	const WrongAnimal	*meta = new WrongAnimal();
	std::cout << std::endl;
	const WrongAnimal	*i = new WrongCat();
	std::cout << std::endl;
		
	std::cout << i->get_type() << " " << std::endl;
	i->makeSound();
	meta->makeSound();
	delete				meta;
	delete				i;
}
