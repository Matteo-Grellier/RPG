#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP
#include <exception>

class EmptyPotion : public std::exception {
    public:
    virtual const char* what() const throw();
};

class IllegalFury : public std::exception {
    bool entering;
    public:
    virtual const char* what() const throw();
    public:
    IllegalFury(bool entering) : entering(entering) {}
};


#endif