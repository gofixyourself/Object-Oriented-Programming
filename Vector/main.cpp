#include <cstring>
#include <cstddef>
#include <iostream>
#include <initializer_list>

#include "errors.hpp"
#include "namespace.hpp"
#include "vector.hpp"

int main(void) {
    try {
        mathvector::MathematicalVector<char> test_vector = {'t', 'e', 's', 't'};

        std::cout << test_vector.contains('e') << std::endl;

        mathvector::MathematicalVector<int> first = {7, 7, 7};
        mathvector::MathematicalVector<int> second = {4, 4, 5};

        mathvector::MathematicalVector<int> result;

        result = first + second;

        for (auto it = result.begin(); it != result.end(); ++it) {
            std::cout << (*it) << " ";
        }
        std::cout << std::endl;

        result *= 5;
        for (auto it = result.begin(); it != result.end(); ++it){
            std::cout << (*it) << " ";
        }
        std::cout << std::endl;

        std::cout << (first > second) << std::endl;
        std::cout << (first < second) << std::endl;
        std::cout << (first == second) << std::endl;

        mathvector::MathematicalVector<int> second_result;
        second_result = first * second;
        std::cout << "Test #2: " << std::endl;
        for (auto it = second_result.begin(); it != second_result.end(); ++it) {
            std::cout << (*it) << " ";
        }
        std::cout << std::endl;

        mathvector::MathematicalVector<int> third_result;
        third_result = first ^ second;
        std::cout << "Test #3: " << std::endl;
        for (auto it = third_result.begin(); it != third_result.end(); ++it) {
            std::cout << (*it) << " ";
        }
        std::cout << std::endl;
    }
    catch (SomeError &error) {
        std::cout << std::endl << std::endl << error.what() << std::endl << std::endl;
    }

    return 0;
}
