#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n;

int bfs(int u, int v, vector<int> * adj) {
    bool visited[n+1];
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push(make_pair(u, 0));
    visited[u] = true;

    pair<int, int> pair;
    int cur, res;
    while (!q.empty()) {
        pair = q.front();
        q.pop();
        cur = pair.first;
        res = pair.second;
        if (cur == v) {
            return res;
        }
        for (int x : adj[cur]) {
            if (!visited[x]) {
                q.push(make_pair(x, res + 1));
                visited[x] = true;
            }
        }
    }

    return 0;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n;

        vector<int> adj[n+1];

        for (int i = 0; i < n-1; ++i) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }


        int q;
        cin >> q;
        while (q--) {
            int u, v;
            cin >> u >> v;
            cout << bfs(u, v, adj) << endl;
        }
    }

    return 0;
}