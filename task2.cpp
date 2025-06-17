#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

void dfs(int v, vector<bool>& visited, vector<vector<int>>& graph) {
    visited[v] = true;
    for (int u : graph[v]) {
        if (!visited[u]) {
            dfs(u, visited, graph);
        }
    }
}

int main() {
    srand(time(0));

    int N, M = 0;
    cout << "Введите число вершин: " << '\n';
    cin >> N;
    cout << "Введите число рёбер: " << '\n';
    cin >> M;

    vector<vector<int>> graph(N);
    vector<bool> edge_exists(N * N, false);

    int edges_created = 0;
    while (edges_created < M) {
        int u = rand() % N;
        int v = rand() % N;
        if (u != v && !edge_exists[u * N + v]) {
            graph[u].push_back(v);
            graph[v].push_back(u);
            edge_exists[u * N + v] = true;
            edge_exists[v * N + u] = true;
            edges_created++;
        }
    }

    cout << "Рёбра в графе:" << endl;
    for (int u = 0; u < N; ++u) {
        for (int v : graph[u]) {
            if (u < v) {
                cout << u << " " << v << endl;
            }
        }
    }

    vector<bool> visited(N, false);
    int components = 0;
    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            dfs(i, visited, graph);
            components++;
        }
    }

    cout << "Минимальное число рёбер для объединения сети: ";
    cout << components - 1 << endl;

    return 0;
}