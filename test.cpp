#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

int	main(void)
{
	int	index;
	



	while (1)
	{
		std::cin >> index;
		std::cout << index;
		
		if (std::cin.fail())
		{
			std::cout << "Invalid input. Please enter a valid integer: ";
			std::cin.clear();                                                  
				// Clear the error flag
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				// Ignore invalid input
		}
		else
		{
			break ; // Input is valid and within range
		}
	}
	return (0);
}
