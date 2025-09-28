#include <iostream>
#include <vector>
#include <string>

std::vector<int> inversePermutation(const std::vector<int>& perm) {
    std::vector<int> inv(perm.size());
    for (size_t i = 0; i < perm.size(); i++) {
        inv[perm[i] - 1] = i + 1;
    }
    return inv;
}

std::vector<int> permutationPower(const std::vector<int>& perm, int power) {
    std::vector<int> result(perm.size());
    for (size_t i = 0; i < perm.size(); i++) {
        int current = i + 1;
        for (int j = 0; j < power; j++) {
            current = perm[current - 1];
        }
        result[i] = current;
    }
    return result;
}

std::string applyPermutation(const std::string& s, const std::vector<int>& perm) {
    std::string result(s.size(), ' ');
    for (size_t i = 0; i < s.size(); i++) {
        result[i] = s[perm[i] - 1];
    }
    return result;
}

int main() {
    int n = 0;
    int k = 0;
    std::cout << "Введите длину слова и число шифрований: ";
    std::cin >> n >> k;

    std::vector<int> perm(n);
    std::cout << "Введите перестановку из " << n << " чисел:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> perm[i];
    }

    std::string encrypted;
    std::cout << "Введите зашифрованное слово: ";
    std::cin >> encrypted;

    std::vector<int> invPerm = inversePermutation(perm);     // получаем обратную перестановку
    std::vector<int> invPk = permutationPower(invPerm, k);  // делаем эту перестановку k раз
    std::string original = applyPermutation(encrypted, invPk); // применяем перестановку к слову

    std::cout << "Дешифрованное слово: " << original << std::endl;

    return 0;
}

