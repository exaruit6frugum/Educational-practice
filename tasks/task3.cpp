#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(time(0));
    
    std::cout << "Введите число улиц и количество запросов:" << '\n';
    int n = 0;
    int k = 0;
    std::cin >> n >> k;

    std::vector<int> snow(n + 1, 0);
    std::vector<std::vector<int>> queries;

    for (int i = 0; i < k; i++) {
        int type = std::rand() % 2 + 1;
        int a = std::rand() % n + 1;
        int b = 0;
        
        if (type == 1) {
            b = std::rand() % 10 + 1;
            queries.push_back({type, a, b});
        } else {
            b = std::rand() % n + 1;
            if (a > b) {
                std::swap(a, b);
            }
            queries.push_back({type, a, b});
        }
    }

    std::cout << "(Автоматически сгенерированные) Запросы:" << std::endl;
    for (const auto& q : queries) {
        std::cout << q[0] << " " << q[1] << " " << q[2] << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Результаты:" << std::endl;
    for (const auto& q : queries) {
        int type = q[0];
        int a = q[1];
        int b = q[2];

        if (type == 1) {
            snow[a] += b;
        } else {
            int sum = 0;
            for (int i = a; i <= b; i++) {
                sum += snow[i];
            }
            std::cout << sum << std::endl;
        }
    }

    return 0;
}