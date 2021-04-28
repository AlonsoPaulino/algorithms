// Depth First Search O(V + E)
#include "../macros.h"

const int N = 100;
vi ady[N];
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
vi color(N, 0); // 0: Not visited, 1: Visiting, 2: Visited and exited
vi t_in(N, 0), t_out(N, 0);
int dfs_t = 0;

void dfs(int u) {
    t_in[u] = dfs_t++;
    color[u] = 1;
    for (int v: ady[u]) {
        if (color[v] == 0) {
            dfs(v);
        }
    }
    color[u] = 2;
    t_out[u] = dfs_t++;
}