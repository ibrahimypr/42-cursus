#include <iostream>
#include <utility>

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		 std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		 return (0);
	}

	std::pair <short, short> numbers;

	for (numbers.first = 1; argv[numbers.first]; numbers.first++)
	{
		numbers.second = -1;
		while (argv[numbers.first][++numbers.second])
			std::cout << (char)toupper(argv[numbers.first][numbers.second]);
	}
	std::cout << std::endl;
}