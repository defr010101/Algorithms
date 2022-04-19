/*
 * Created by defr010101 19.04.2022
 * Задача подсчёта компонент связности
 */
#include <bits/stdc++.h>
using namespace std;

void DFS(const vector<vector<pair<int,int>>>& graph, vector<bool>& visited, int vertex) {
    visited[vertex] = true;
    for (auto v:graph[vertex]) {
        int node = v.first;
        if (!visited[node]) {
            DFS(graph, visited, node);
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int n_vertices, n_edges;
    cin >> n_vertices >> n_edges;
    vector<vector<pair<int,int>>> graph(n_vertices);
    vector<bool> visited(n_vertices, false);

    int a, b, w;
    for (int i = 0; i < n_edges; i++) {
        cin >> a >> b >> w;
        graph[a-1].emplace_back(b-1, w);
    }

    int start = 1;

    DFS(graph, visited, start - 1);

    int count = 1;
    for (int i = 1; i < n_vertices; i++) {
        if (!visited[i]) {
            count++;
            DFS(graph, visited, i);
        }
    }

    cout << count;

    return 0;
}
