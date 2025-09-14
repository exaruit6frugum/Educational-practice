#include <iostream>
#include <vector>
#include <string>

std::vector<int> inversePermutation(const std::vector<int>& p) {
    std::vector<int> inv(p.size());
    for (size_t i = 0; i < p.size(); i++) {
        inv[p[i] - 1] = i + 1;
    }
    return inv;
}

std::vector<int> permutationPower(const std::vector<int>& p, int power) {
    std::vector<int> result(p.size());
    for (size_t i = 0; i < p.size(); i++) {
        int current = i + 1;
        for (int j = 0; j < power; j++) {
            current = p[current - 1];
        }
        result[i] = current;
    }
    return result;
}

std::string applyPermutation(const std::string& s, const std::vector<int>& p) {
    std::string result(s.size(), ' ');
    for (size_t i = 0; i < s.size(); i++) {
        result[i] = s[p[i] - 1];
    }
    return result;
}

int main() {
    int n, k;
    std::cout << "Введите длину слова и число шифрований: ";
    std::cin >> n >> k;

    std::vector<int> p(n);
    std::cout << "Введите перестановку из " << n << " чисел:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }

    std::string encrypted;
    std::cout << "Введите зашифрованное слово: ";
    std::cin >> encrypted;

    std::vector<int> invP = inversePermutation(p);     // получаем обратную перестановку
    std::vector<int> invPk = permutationPower(invP, k);  // делаем эту перестановку k раз
    std::string original = applyPermutation(encrypted, invPk); // применяем перестановку к слову

    std::cout << "Дешифрованное слово: " << original << std::endl;

    return 0;
}

