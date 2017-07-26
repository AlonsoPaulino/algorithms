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

struct Point{
  int x, y;
  bool operator < (const Point &p) const {
    return (x < p.x || (x == p.x && y < p.y));
  }
  bool operator == (const Point &p) const {
    return (x == p.x && y == p.y);
  }
};

int cross(const Point &O, const Point &A, const Point &B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

//Monotone chain algorithm O(n * Log(n))
//Returns a vector containing the points that are part of the convex hull.
vector<Point> convexHull(vector<Point> v) {
    int n = sz(v), k = 0;
    vector<Point> h(2 * n);

    sort(all(v));

    for (int i = 0; i < n; ++i) {
        while (k >= 2 && cross(h[k - 2], h[k - 1], v[i]) < 0) k--;
        h[k++] = v[i];
    }

    for (int i = n - 2, t = k + 1; i >= 0; --i) {
        while (k >= t && cross(h[k - 2], h[k - 1], v[i]) < 0) k--;
        h[k++] = v[i];
    }

    h.resize(k), h.popb();

    return h;
}