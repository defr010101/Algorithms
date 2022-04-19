#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10];
bool visited[10];
int n = 5;

void dfs(int s) {
    if (visited[s]) return;
    visited[s] = true;
    cout << s << " ";
    for (auto u : adj[s]) {
        dfs(u);
    }
}

void bfs(int s) {
    queue<int> q;
    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        int a = q.front(); q.pop();
        cout << a << " ";
        for (auto u : adj[a]) {
            if (visited[u]) continue;
            visited[u] = true;
            q.push(u);
        }
    }
}

void addEdge(int a, int b) {
    adj[a].push_back(b);
}

int main() {
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(3, 4);
    addEdge(4, 2);
    addEdge(4, 5);
    addEdge(5, 3);

    dfs(1);

    return 0;
}
