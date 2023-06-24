
#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "str address :       " << &str << std::endl;
	std::cout << "stringPTR address : " << stringPTR << std::endl;
	std::cout << "stringREF address : " << &stringREF << std::endl;

	std::cout << "str value :       " << str << std::endl;
	std::cout << "stringPTR value : " << *stringPTR << std::endl;
	std::cout << "stringREF value : " << stringREF << std::endl;

	return 0;
}