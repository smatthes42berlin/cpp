#include <cstring>
#include <iostream>

int	main(int argc, char *argv[])
{
	int		str_len;
	char	*arg;
	char	c;

	if (argc <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		str_len = std::strlen(argv[i]);
		arg = argv[i];
		for (int j = 0; j < str_len; j++)
		{
			c = std::toupper(arg[j]);
			std::cout << c;
		}
	};
	std::cout << std::endl;
	return (0);
}
