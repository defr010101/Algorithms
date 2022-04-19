//
// Created by Mikhail on 19.04.2022.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 100;
vector<tuple<int,int,int>> edges;
int dist[N];

void addEdge(int a, int b, int w) {
    edges.push_back({a, b, w});
}

void algo(int x) {
    for (int i = 1; i <= 5; i++) {
        dist[i] = INFINITY;
    }
    dist[x] = 0;

    for (int i = 1; i <= 4; i++) {
        for (auto e : edges) {
            int a, b, w;
            tie(a, b, w) = e;
            dist[b] = min(dist[b], dist[a] + w);
        }
    }
}

int main() {

    addEdge(1, 2, 2);
    addEdge(1, 4, 7);
    addEdge(1, 3, 3);
    addEdge(2, 4, 3);
    addEdge(3, 4, -2);
    addEdge(2, 5, 5);
    addEdge(4, 5, 2);

    int a = 1;
    algo(1);

    int b = 5;
    int min = dist[b];

    cout << "The minimal distance from " << a << " to " << b << " is " << min;

    return 0;
}
