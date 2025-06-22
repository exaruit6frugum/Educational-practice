#include <iostream>
#include <vector>
#include <string>

std::vector<int> inversePermutation(const std::vector<int>& p) {
    std::vector<int> inv(p.size());
    for (size_t i = 0; i < p.size(); ++i) {
        inv[p[i] - 1] = i + 1;
    }
    return inv;
}

std::vector<int> permutationPower(const std::vector<int>& p, int power) {
    std::vector<int> result(p.size());
    for (size_t i = 0; i < p.size(); ++i) {
        int current = i + 1;
        for (int j = 0; j < power; ++j) {
            current = p[current - 1];
        }
        result[i] = current;
    }
    return result;
}

std::string applyPermutation(const std::string& s, const std::vector<int>& p) {
    std::string result(s.size(), ' ');
    for (size_t i = 0; i < s.size(); ++i) {
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
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
    }

    std::string encrypted;
    std::cout << "Введите зашифрованное слово: ";
    std::cin >> encrypted;

    std::vector<int> invP = inversePermutation(p);
    std::vector<int> invPk = permutationPower(invP, k);
    std::string original = applyPermutation(encrypted, invPk);

    std::cout << "Дешифрованное слово: " << original << std::endl;

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <string>
// #include <random>
// #include <algorithm>
// #include <ctime>

// std::vector<int> generateRandomPermutation(int n, std::mt19937& rng) {
//     std::vector<int> p(n);
//     for (int i = 0; i < n; ++i) {
//         p[i] = i + 1;
//     }
//     std::shuffle(p.begin(), p.end(), rng);
//     return p;
// }

// std::vector<int> inversePermutation(const std::vector<int>& p) {
//     std::vector<int> inv(p.size());
//     for (size_t i = 0; i < p.size(); ++i) {
//         inv[p[i] - 1] = i + 1;
//     }
//     return inv;
// }

// std::string applyPermutation(const std::string& s, const std::vector<int>& p) {
//     std::string result(s.size(), ' ');
//     for (size_t i = 0; i < s.size(); ++i) {
//         result[i] = s[p[i] - 1];
//     }
//     return result;
// }

// int main() {
//     std::mt19937 rng(std::time(0));
    
//     int n, k;
//     std::cout << "Введите длину слова: \n";
//     std::cin >> n;
//     std::cout << "Введите число перестановок: ";
//     std::cin >> k;
    
//     std::string original;
//     std::uniform_int_distribution<char> dist('a', 'z');
//     for (int i = 0; i < n; ++i) {
//         original += dist(rng);
//     }
    
//     std::cout << "\nСгенерированное зашифрованное слово: " << original << std::endl;
    
//     std::vector<std::vector<int>> permutations;
//     std::string current = original;
    
//     for (int i = 1; i <= k; ++i) {
//         std::vector<int> p = generateRandomPermutation(n, rng);
//         permutations.push_back(p);
        
//         current = applyPermutation(current, p);
        
//         std::cout << "\nШаг " << i << ":" << std::endl;
//         std::cout << "Перестановка:";
//         for (int num : p) {
//             std::cout << " " << num;
//         }
//         std::cout << "\nРезультат: " << current << std::endl;
//     }
    
//     std::string decrypted = current;
//     for (int i = k - 1; i >= 0; --i) {
//         std::vector<int> inv_p = inversePermutation(permutations[i]);
//         decrypted = applyPermutation(decrypted, inv_p);
//     }
    
//     std::cout << std::endl;
//     std::cout << "Зашифрованное слово: " << current << std::endl;
//     std::cout << "Дешифрованное слово: " << decrypted << std::endl;
    
//     return 0;
// }

