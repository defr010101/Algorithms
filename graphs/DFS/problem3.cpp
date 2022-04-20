/*
 * Created by defr010101 20.04.2022
 * Нахождения цикла размера 3, с минимальным суммарный весом
 */

#include <bits/stdc++.h>
using namespace std;

enum color {
    WHITE, GRAY, BLACK
};

void DFS(const vector<vector<pair<int,int>>>& adj, vector<color>& visited,
         vector<int>& temp, vector<int>& res, int a, int from) {
    visited[a] = GRAY;
    for (auto p:adj[a]) {
        int b = p.first;
        if (b == from) continue;
        temp.push_back(a);
        if (visited[b] == WHITE) {
            DFS(adj, visited, temp, res, b, a);
        }
        if (visited[b] == GRAY) {
            if (temp.size() == 3) {
                if (res.empty()) {
                    res = temp;
                }
                else if (adj[temp[0]][temp[1]].second + adj[temp[1]][temp[2]].second +
                        adj[temp[2]][temp[0]].second < adj[res[0]][res[1]].second +
                        adj[res[1]][res[2]].second + adj[res[2]][res[0]].second) {
                    res = temp;
                }
            }

            temp.clear();
        }
    }
    visited[a] = BLACK;
}

int main() {
    freopen("input.txt", "r", stdin);
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int,int>>> adj(N);
    vector<color> visited(N, WHITE);

    int a, b, w;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> w;
        adj[a-1].emplace_back(b-1, w);
    }

    vector<int> temp;
    vector<int> res;
    DFS(adj, visited, temp, res, 0, -1);

    for (auto v:res) {
        cout << v+1;
    }

    return 0;
}
