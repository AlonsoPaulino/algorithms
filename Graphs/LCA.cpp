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

// See https://www.topcoder.com/community/data-science/data-science-tutorials/range-minimum-query-and-lowest-common-ancestor/#A%20O(N),%20O(1)%20algorithm%20for%20the%20restricted%20RMQ

const int N = 1e5 + 17;
const int LOGN = 17;

vi g[N];
int p[N][LOGN], h[N];

void dfs(int v = 0) {
    for (int i = 1; i < LOGN; ++i) {
        p[v][i] = p[p[v][i - 1]][i - 1];
    }
    for (int i = 0; i < sz(g[v]); ++i) {
        int u = g[v][i];
        h[u] = h[v] + 1;
        p[u][0] = v;
        dfs(u);
    }
}

int lca(int v, int u) {
    if (h[v] > h[u]) swap(v, u);
    for (int i = 0; i < LOGN; ++i) {
        if (h[u] - h[v] >> i & 1) {
            u = p[u][i];
        }
    }
    for (int i = LOGN - 1; i >= 0; --i) {
        if (p[v][i] != p[u][i]) {
            v = p[v][i], u = p[u][i];
        }
    }
    return v == u ? v : p[v][0];
}

int main() {
    int x, y;
    for (int i = 0; i < 10; ++i) {
        cin >> x >> y;
        g[x].pb(y);
    }
    dfs();
    for (int i = 0; i < 5; ++i) {
        cin >> x >> y;
        cout << lca(x, y) << "\n";
    }
}
