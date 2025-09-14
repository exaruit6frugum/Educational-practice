#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

void DFS(int v, std::vector<bool>& visited, std::vector<std::vector<int>>& graph) {
    visited[v] = true;
    for (int u : graph[v]) {
        if (!visited[u]) {
            DFS(u, visited, graph);
        }
    }
}

int main() {
    std::srand(time(0));

    int n = 0;
    int m = 0;
    std::cout << "Введите число вершин: " << '\n';
    std::cin >> n;
    std::cout << "Введите число рёбер: " << '\n';
    std::cin >> m;

    std::vector<std::vector<int>> graph(n);
    std::vector<std::vector<bool>> edge_exists(n, std::vector<bool>(n, false));

    int edges_created = 0;
    while (edges_created < m) {
        int u = std::rand() % n;
        int v = std::rand() % n;
        if (u != v && !edge_exists[u][v]) {
            graph[u].push_back(v);
            graph[v].push_back(u);
            edge_exists[u][v] = true;
            edge_exists[v][u] = true;
            edges_created++;
        }
    }

    std::cout << "Рёбра в графе:" << '\n';
    for (int u = 0; u < n; u++) {
        for (int v : graph[u]) {
            if (u < v) {
                std::cout << u << " " << v << '\n';
            }
        }
    }

    std::vector<bool> visited(n, false);
    int components = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i, visited, graph);
            components++;
        }
    }

    std::cout << "Минимальное число рёбер для объединения сети: ";
    std::cout << components - 1 << '\n';

    return 0;
}