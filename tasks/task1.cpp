#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

int main() {
    std::cout << "Введите число ступеней горы:" << '\n';
    int count = 0;
    std::cin >> count;

    std::srand(std::time(0));

    std::vector<std::vector<int>> step(count);
    int way_sum = 0;
    std::vector<int> way(count);
    
    step[0].resize(1);
    step[0][0] = std::rand() % 1000 + 1;

    int idx_last_min = 0;
    int min = 0;

    way[0] = step[0][0];

    for (int i = 1; i < count; i++) {

        step[i].resize(i + 1);

        for (int j = 0; j < i + 1; j++) {
            step[i][j] = std::rand() % 1000 + 1;
        }
        
        min = step[i][idx_last_min];
        
        if (step[i][idx_last_min + 1] < min) {
            min = step[i][idx_last_min + 1];
            idx_last_min += 1;
        }

        way_sum += min;
        way[i] = min;
    }

    std::cout << "Время кратчайшего пути: " << '\n';
    std::cout << way_sum << '\n';

    std::cout << "Кратчайший путь: " << '\n';
    for (int i = 0; i < count; i++) {
        std::cout << way[i] << ' ';
    }
    
    std::cout << '\n';

    std::cout << "Карта горы:\n" ;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < i + 1; j++) {
            std::cout << step[i][j] << ' ';
        }
        std::cout << '\n';
    }
}