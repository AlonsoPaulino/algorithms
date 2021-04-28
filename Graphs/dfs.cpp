#include "../macros.h"

const int N = 100;

vi ady[N];
vector<bool> vis(N);

// Recursive Approach
// u: root node to start the dfs
void dfs(int u) {
    vis[u] = true; // Node u is set as visited
    
    for (auto v: ady[u]) {
        // If not visited, run dfs with v as root
        if (!vis[v]) {
            dfs(v);
        }
    }
}

// Iterative approach
// u: root node to start the dfs
void dfs(int u) {
    stack<int> st;
    st.push(u);

    while (!st.empty()) {
        // Get top node in the stack and remove it.
        int x = st.top(); st.pop();
        // Node u is set as visited
        vis[x] = true;

        for (auto v: ady[u]) {
            // If not visited, add to the stack
            if (!vis[v]) {
                st.push(v);
            }
        }
    }
}