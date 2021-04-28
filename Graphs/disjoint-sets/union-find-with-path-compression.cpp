#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define pss pair<string, string>
#define mii map<int, int>
#define vi vector<int>
#define vb vector<bool>
#define mp make_pair
#define pb push_back
#define popb pop_back
#define fi first
#define se second
#define mset(v, x) memset(v, x, sizeof(v))
#define mset2d(v, x, n) memset(v, x, sizeof(v[0][0]) * n * n)
#define mset2dd(v, x, n, m) memset(v, x, sizeof(v[0][0]) * n * m)
#define debug(x) cout<<#x<<" : "<<x<<endl
#define debug2(x,y) cout<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cout<<"hola papa"<<endl
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const int N = 10000000;
vi v(N);

/* find will return the parent of the set where x is involved */
int find(int x) {
  return (x == v[x]) ? x : v[x] = find(v[x]);
}

/* join the sets where x and y are involved */
void join(int x, int y) {
  v[find(x)] = find(y);
}

int main() {
  int t = 5, x, y, a, b;
  for (int i = 0; i < N; ++i) {
    v[i] = i;
  }
  /* Read the relations */
  for (int i = 0; i < t; ++i) {
    cin >> x >> y;
    join(x, y);
  }
  /* Read the queries */
  for (int i = 0; i < t; ++i) {
    cin >> a >> b;
    if (find(a) == find(b)) {
      cout << "Both elements are involved in the same set\n";
    } else {
      cout << "Both elements are involved in different sets\n";
    }
  }
}
