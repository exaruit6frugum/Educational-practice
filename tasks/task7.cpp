#include <iostream>
#include <cctype>
#include <string>

int main() {
    std::string str;
    std::cout << "Введите строку из шести символов: \n";
    std::cin >> str;

    bool isValid = true;
    if (str.length() != 6) {
        isValid = false;
    }

    if (isValid) {
        if (!std::isalpha(str[0]) || !std::isupper(str[0])) {
            isValid = false;
        }

        for (int i = 1; i < 4; i++) {
            if (!std::isdigit(str[i])) {
                isValid = false;
            }
        }

        for (int i = 4; i < 6; i++) {
            if (!std::isalpha(str[i]) || !std::isupper(str[i])) {
                isValid = false;
            }
        }
    }

    if (isValid) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    return 0;
}