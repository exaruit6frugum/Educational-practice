#include <iostream>
#include <cctype>
#include <string>

int main() {
    std::string input;
    std::cout << "Введите строку из шести символов: \n";
    std::cin >> input;

    bool isValid = true;

    if (input.length() != 6) {
        isValid = false;
    }

    if (isValid) {
        if (!std::isalpha(input[0]) || !std::isupper(input[0])) {
            isValid = false;
        }

        for (int i = 1; i <= 3; i++) {
            if (!std::isdigit(input[i])) {
                isValid = false;
            }
        }

        for (int i = 4; i <= 5; i++) {
            if (!std::isalpha(input[i]) || !std::isupper(input[i])) {
                isValid = false;
            }
        }
    }

    std::cout << "Результат: \n";
    if (isValid) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}