#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    
    cout << "Введите число улиц и количество запросов:" << '\n';
    int n, k;
    cin >> n >> k;

    vector<int> snow(n + 1, 0);
    vector<vector<int>> queries;

    for (int i = 0; i < k; i++) {
        int type = rand() % 2 + 1;
        int a = rand() % n + 1;
        int b;
        
        if (type == 1) {
            b = rand() % 10 + 1;
            queries.push_back({type, a, b});
        } else {
            b = rand() % n + 1;
            if (a > b) swap(a, b);
            queries.push_back({type, a, b});
        }
    }

    cout << "(Автоматически сгенерированные) Запросы:" << endl;
    for (const auto& q : queries) {
        cout << q[0] << " " << q[1] << " " << q[2] << endl;
    }
    cout << endl;

    cout << "Результаты:" << endl;
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
            cout << sum << endl;
        }
    }

    return 0;
}