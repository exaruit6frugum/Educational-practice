#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n = 0;
    std::cout << "Введите количество запросов: \n";
    std::cin >> n;

    int a = 0;
    int b = 0;
    int x = 0;
    int y = 0;
    int result = 0;
    std::vector<int> vec_result(n);

    int j = 0;
    std::cout << "Введите запросы: \n" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> a >> b >> x >> y;
        
        result = std::min(a + b, x + y) - std::max(0, b - x);
        vec_result[j++] = result;
       
    }
    std::cout << "Результаты: \n";
    for (int i = 0; i < n; i++) {
        std::cout << vec_result[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}
