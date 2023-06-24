#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include "contact.hpp"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


class Phonebook
{
    private:
        Contact _contacts[8];
        int _index;
    public:
        Phonebook();
	    ~Phonebook();

        void    add(int i);
        void    search();
        int     get_count();  
};

#endif