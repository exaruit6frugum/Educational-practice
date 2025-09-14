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
    int usedB = 0;
    int remainingX = 0;
    int availableForA = 0;
    int usedA = 0;
    int result = 0;
    std::vector<int> vec_result(n);

    int j = 0;
    std::cout << "Введите запросы: \n" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> a >> b >> x >> y;
        
        usedB = std::min(b, x);
        remainingX = x - usedB;
        
        availableForA = remainingX + y;
        usedA = std::min(a, availableForA);
        
        result = usedA + usedB;
        vec_result[j++] = result;
       
    }
    std::cout << "Результаты: \n";
    for (int i = 0; i < n; i++) {
        std::cout << vec_result[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}
