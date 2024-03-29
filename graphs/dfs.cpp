// Depth First Search O(V + E)
#include <bits/stdc++.h>
using namespace std;

const int N = 100;
vector<int> ady[N];
vector<bool> vis(N);

// Recursive Approach
void dfs(int u) {
    vis[u] = true;
    
    for (auto v: ady[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

// Iterative approach
void dfs(int u) {
    stack<int> st;
    st.push(u);

    while (!st.empty()) {
        int x = st.top(); st.pop();
        vis[x] = true;

        for (auto v: ady[u]) {
            if (!vis[v]) {
                st.push(v);
            }
        }
    }
}

// Used to classify edges
vector<int> color(N, 0); // 0: White (not discovered yet), 1: Grey (discovered), 2: Black (finished)
vector<int> d(N, 0); // Discovery time
vector<int> f(N, 0); // Finishing time
vector<int> p(N, -1); // Parents
int t = 0;

void dfs(int u) {
    d[u] = t++;
    color[u] = 1;
    for (int v: ady[u]) {
        if (color[v] == 0) {
            p[v] = u;
            dfs(v);
        }
    }
    color[u] = 2;
    f[u] = t++;
}