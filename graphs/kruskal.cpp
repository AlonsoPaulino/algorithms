// Kruskal - Minimum Spanning Tree O(E * logE)
#include <bits/stdc++.h>
#define pii pair<int, int>
#define piii pair<int, pii>
#define se second
#define fi first
using namespace std;

const int N = 100;
vector<piii> edges;
vector<piii> mst;
int cost = 0;

// + Disjoint Sets (Union-Find)
void join(int x, int y) {}
int find(int x) { return x; }
// - End Disjoint Sets

void kruskal() {
    sort(edges.begin(), edges.end());
    for (auto e: edges) {
        if (find(e.se.fi) != find(e.se.se)) {
            join(e.se.fi, e.se.se);
            mst.push_back(e);
            cost += e.fi;
        }
    }
}