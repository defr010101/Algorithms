/*
 * Created by defr010101 19.04.2022
 * Проверка графа на двудольность
 */
#include <bits/stdc++.h>
using namespace std;

enum color {
    RED, BLUE, GRAY
};

color invert_color(color a) {
    if (a == RED) {
        return BLUE;
    }
    return RED;
}

bool DFS(const vector<vector<pair<int,int>>>& graph, vector<color>& visited, int vertex, color prev) {
    visited[vertex] = invert_color(prev);
    for (auto v:graph[vertex]) {
        int node = v.first;
        if (visited[node] == GRAY) {
            return DFS(graph, visited, node, invert_color(visited[vertex]));
        }
        if (visited[node] == visited[prev]) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("input.txt", "r", stdin);

    int n_vertices, n_edges;
    cin >> n_vertices >> n_edges;
    vector<vector<pair<int,int>>> graph(n_vertices);
    vector<color> visited(n_vertices, GRAY);

    int a, b, w;
    for (int i = 0; i < n_edges; i++) {
        cin >> a >> b >> w;
        graph[a-1].emplace_back(b-1, w);
    }

    int start = 1;

    if (DFS(graph, visited, start - 1, GRAY)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
