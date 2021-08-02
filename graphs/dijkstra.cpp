// Dijkstra O((V + E) log E)
#include <bits/stdc++.h>
#define sz(x) (int) x.size()
#define pii pair<int, int>
using namespace std;

const int INF = 1e9 + 5;
const int N = 50;

vector<int> ady[N], adyw[N];
vector<int> dist(N, INF);

void dijkstra(int root) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, root}), dist[root] = 0;
    while (!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int u = p.second, d = p.first;
        for (int i = 0; i < sz(ady[u]); ++i) {
            int v = ady[u][i], w = adyw[u][i];
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({ dist[v], v });
            }
        }
    }
}


