#ifndef ERRORS_HPP
#define ERRORS_HPP

#include <exception>
##include <string>

class SomeError : public std::exception {
protected:
    std::string error_message;

public:
    SomeError() = default;

    explicit SomeError(const char* error_message) {
        this->error_message = error_message;
    }

    explicit SomeError(std::string& error_message) {
        this->error_message = error_message;
    }
};

class MemoryError : public SomeError {
public:
    MemoryError() = default;

    explicit MemoryError(const char* error_message)
            : SomeError(error_message) {
    }

    explicit MemoryError(std::string& error_message)
            : SomeError(error_message) {
    }

    virtual const char* what() const noexcept {
        return error_message.empty() ? "Something went wrong!" : error_message.c_str();
    }
};

#endif // ERRORS_HPP
