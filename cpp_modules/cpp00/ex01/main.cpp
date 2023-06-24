#include "phonebook.hpp"
#include "contact.hpp"

void    printHeader()
{
    std::cout << "\t************************************" << std::endl;
	std::cout << "\t* Welcome to my awesome phonebook! *" << std::endl;
	std::cout << "\t* Use: ADD, SEARCH, EXIT           *" << std::endl;
	std::cout << "\t* ADD - add and save new contact   *" << std::endl;
	std::cout << "\t* SEARCH - show contact            *" << std::endl;
	std::cout << "\t* EXIT - close program             *" << std::endl;
	std::cout << "\t************************************" << std::endl;
}

int main(void)
{
    Phonebook phone_book;
    std::string input;
    int i = 0;

    printHeader();
    while (input != "EXIT")
    {
        std::cout << "Enter the command: ";
        std::cin >> input;

        if (input == "ADD")
        {
            phone_book.add(i);
            if (i == 7)
                i = 0;
            else
                i++;
        }
        else if (input == "EXIT")
            std::cout << "Bye" << std::endl;
        else if (input == "SEARCH")
            phone_book.search();
        else
				std::cout << "Wrong command!" << std::endl;
    }
    return 0;
}