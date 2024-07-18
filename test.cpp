#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

int	main(void)
{
	std::string input_gl;
	std::string input_cin;
	while (1)
	{
		std::cout << "Enter getline" << std::endl;
		std::getline(std::cin, input_gl);
		std::cout << "getline enter = " << input_gl << std::endl
					<< std::endl;
		std::cout << "Enter cin" << std::endl;
		std::cin >> input_cin;
		std::cout << "cin enter = " << input_cin << std::endl
					<< std::endl;
		if (std::cin.eof())
			break ;
		std::cin.clear();
		std::cin.eof();
		std::cin.fail();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return (0);
}
