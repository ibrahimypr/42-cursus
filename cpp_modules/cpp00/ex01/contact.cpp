#include "contact.hpp"

void		Contact::setFirstName(std::string name) {this->name = name;}
void        Contact::setLastName(std::string surname) {this->surname = surname;}
void        Contact::setNickname(std::string nickname) {this-> nickname = nickname;}
void        Contact::setPhoneNum(std::string number) {this-> number = number;}
void        Contact::setSecret(std::string secret) {this-> secret = secret;}

std::string	Contact::getFirstName() {return (this->name);}
std::string	Contact::getLastName() {return (this-> surname);}
std::string	Contact::getNickname() {return (this-> nickname);}
std::string	Contact::getPhoneNum() {return (this-> number);}
std::string	Contact::getSecret() {return (this->secret);}

Contact::Contact(){}

Contact::~Contact(){}

void Contact::add_contact()
{
	std::cout << "Input first name: ";
	std::cin >> this->name;
	std::cout << "Input last name: ";
	std::cin >> this->surname;
	std::cout << "Input nick name: ";
	std::cin >> this->nickname;
	std::cout << "Input phone number: ";
	std::cin >> this->number;
	std::cout << "Input darkest secret: ";
	std::cin >> this->secret;
}

void		Contact::printContact() {
	std::cout << "First name : " << this->name << std::endl;
	std::cout << "Last name: " << this->surname << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone number: " << this->number << std::endl;
	std::cout << "Secret: " << this->secret << std::endl;
}