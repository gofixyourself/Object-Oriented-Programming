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

class InputSizeError: public SomeError {
public:
    const char *what() {
        return "You entered a number less than zero. Try again.";
    }
};





#endif // ERRORS_HPP
