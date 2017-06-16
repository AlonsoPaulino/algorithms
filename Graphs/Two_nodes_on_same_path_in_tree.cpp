#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define pill pair<int, long long>
#define mii map<int, int>
#define vi vector<int>
#define vll vector<long long>
#define vs vector<string>
#define vb vector<bool>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define popb pop_back
#define all(v) v.begin(),v.end()
#define mod(x, m) ((x % m) + m) % m
#define mset(v, x) memset(v, x, sizeof(v))
#define mset2d(v, x, n) memset(v, x, sizeof(v[0][0]) * n * n)
#define mset2dd(v, x, n, m) memset(v, x, sizeof(v[0][0]) * n * m)
#define debug(x) cerr<<#x<<" : "<<x<<endl
#define debug2(x,y) cerr<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cerr<<"hola papa"<<endl
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const int MAX = 100001;

bool visit[MAX] = {0};

int intime[MAX], outtime[MAX], timer = 0;

void dfs(vi g[], int v) {
    visit[v] = 1;
    ++timer;
    intime[v] = timer;
    for (int i = 0; i < sz(g[v]); ++i) {
        if (!visit[g[v][i]]) {
            dfs(g, g[v][i]);
        }
    }
    ++timer;
    outtime[v] = timer;
}

bool query(int u, int v) {
    /* Intime: When we visit the node for the first time */
    /* Outtime: If we again visit the node later but there is no children unvisited */
    /* NOTE: Any node in its sub-tree will always have intime < its children because it is always visited
        first before children (DFS) and will have outtime > all nodes in its sub-tree because before
        nothing the outtime it waits for all of its children to be marked as visited.*/
    return (intime[u] < intime[v] && outtime[u] > outtime[v]) ||
            (intime[v] < intime[u] && outtime[v] > outtime[u]);
}

int main() {
    int n = 9, u, v;
    vi g[n + 1];
    g[1].pb(2), g[1].pb(3), g[3].pb(6), g[2].pb(4), g[2].pb(5), g[5].pb(7), g[5].pb(8), g[5].pb(9);
    dfs(g, 1);
    while (cin >> u >> v) {
        cout << (query(u, v) ? "Same path :)\n" : "Not on same path :(\n");
    }
    return 0;
}

