#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		std::string literal = argv[1];
		ScalarConverter::convert(literal);
		return 0;
	}
	std::cerr << BOLD << RED << "ONE AND ONLY ONE ARGUMENT NEEDED" << RESET << std::endl;
	return 1;
}