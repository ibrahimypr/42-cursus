#ifndef CONTACT_HPP
# define CONTACT_HPP
#include <iostream>
#include <string>
#include <iomanip>

class   Contact
{
    private:
        std::string name;
        std::string surname;
        std::string nickname;
        std::string number;
        std::string secret;
    public:

        Contact();
	    ~Contact();

        std::string getFirstName();
        std::string getLastName();
        std::string getNickname();
        std::string getPhoneNum();
        std::string getSecret();

        void    setFirstName(std::string name);
        void    setLastName(std::string surname);
        void    setNickname(std::string nickname);
        void    setPhoneNum(std::string number);
        void    setSecret(std::string secret);

        void    add_contact();
        void    printContact();
};

#endif