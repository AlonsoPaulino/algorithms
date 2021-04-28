// Depth First Search O(V + E)
#include "../macros.h"

const int N = 100;
vi ady[N]; // Adjacency list
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