#include "phonebook.hpp"

Phonebook::Phonebook()
{
    this->_index = 0;
}

Phonebook::~Phonebook(){}

int Phonebook::get_count()
{
	return this->_index;
}

void    Phonebook::add(int i)
{
    if (this->get_count() <= 7)
        this->_index += 1;
    this->_contacts[i].add_contact();
}

std::string check_len(std::string str)
{
	std::string new_str;

	new_str = str;
	if (str.length() > 10)
	{
		new_str.insert(9, ".");
		new_str = new_str.substr(0, 10);
	}
	return new_str;
}

void    Phonebook::search()
{
    int i = 0;
    int index = this->get_count();

    std::cout << "+----------+----------+----------+----------+\n";
	std::cout << "|" << std::setw(10) << "index" << "|" \
		<< std::setw(10) << "first name" << "|"\
		<< std::setw(10) << "last name" << "|" \
		<< std::setw(10) << "nickname" << "|\n";
	std::cout << "+----------+----------+----------+----------+\n";
    while (index > i )
    {
        std::cout << "|" << std::setw(10) << i << "|" \
 			<< std::setw(10) << check_len(_contacts[i].getFirstName()) << "|" \
 			<< std::setw(10) << check_len(_contacts[i].getLastName()) << "|" \
 			<< std::setw(10) << check_len(_contacts[i].getNickname()) << "|" \
 			<< std:: endl;
		std::cout << "+----------+----------+----------+----------+\n";
		i++;
    }
    std::cout << "Enter index of contact to show more info: ";
	if (std::cin >> i)
	{
		if (i >= 0 && i < index)
			this->_contacts[i].printContact();
		else
			std::cout << "Index is not correct!" << std:: endl;
	}
	else
		std::cout << "std::cin error" << std:: endl;
}