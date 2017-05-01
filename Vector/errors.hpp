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
};

class IteratorError: public SomeError {
public:
    const char *what() {
        return "Some problems with iterators.";
    }
};

class DivideZeroError: public SomeError {
public:
    const char *what() {
        return "You divide by zero.";
    }
};

class MultiplicationError: public SomeError {
public:
    const char *what() {
        return "The operation of multiplication a mathematical vector is only possible for three dimensions.";
    }
};

class DifferentSizesError: public SomeError {
public:
    const char *what() {
        return "You have entered different sizes of vectors. You can't do it."
    }
}

#endif // ERRORS_HPP
