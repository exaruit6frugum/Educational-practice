#include <iostream>
#include <vector>

int main() {
    int height;
    int width;
    
    std::cout << "Введите высоту матрицы: ";
    std::cin >> height;
    std::cout << "Введите ширину матрицы: ";
    std::cin >> width;

    std::vector<std::vector<int>> matrix(height, std::vector<int>(width));

    std::cout << "Введите матрицу построчно:" << std::endl;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    int min_row = height;
    int max_row = 0;
    int min_col = width;
    int max_col = 0;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (matrix[i][j] == 1) {
                if (i < min_row) {
                    min_row = i;
                }
                if (i > max_row) {
                    max_row = i;
                }
                if (j < min_col) {
                    min_col = j;
                }
                if (j > max_col) {
                    max_col = j;
                }
            }
        }
    }

    std::cout << "Координаты ограничивающего прямоугольника:" << std::endl;
    std::cout << min_row - 1 << " " << min_col - 1 << " " << max_row + 1 << " " << max_col + 1 << std::endl;

    return 0;
}