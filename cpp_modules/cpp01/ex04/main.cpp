#include <iostream>
#include <fstream>

void	replace(std::string str, char **av)
{
	std::ofstream	outFile;
	int				pos;

	outFile.open((std::string)av[1] + ".replace");
	for (int i = 0; i < (int)str.length(); i++)
	{
		pos = str.find(av[2], i);
		if (pos != -1 && i == pos)
		{
			outFile << av[3];
		}
		else
			outFile << str[i];
	}
	outFile.close();
}

int	main(int ac, char **av)
{
	std::ifstream	readFile;
	std::string		str;
	char c;

	if (ac != 4)
	{
		std::cout << "Wrong args! usage : ./file <filename> <str1> <str2>" << std::endl;
		return (1);
	}
	readFile.open(av[1]);
	if (readFile.fail())
	{
		std::cout << "Wrong file name !" << std::endl;
		return (1);
	}
	while (!readFile.eof() && readFile >> std::noskipws >> c)
		str += c;
	readFile.close();
	replace(str, av);
	return (0);
}