#ifndef ERRORS_HPP
#define ERRORS_HPP

#include <exception>

class SomeError : public std::exception {
public:
    virtual const char *what() {
        return "Ooops!";
    }
};

class MemoryError : public SomeError {
public:
    const char *what() {
        return "Problems with memory allocation.";
    }
};

class WrongInputError: public SomeError {
public:
    const char *what() {
        return "You entered a number less than zero. Please, try again.";
    }
};

class EmptyInputError: public SomeError {
public:
    const char *what() {
        return "You did't enter anything. Please, try again.";
    }
}





#endif // ERRORS_HPP
