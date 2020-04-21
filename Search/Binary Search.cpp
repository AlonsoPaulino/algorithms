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

/*
* Credits: https://www.topcoder.com/community/competitive-programming/tutorials/binary-search
*
* Try these problems out!:
* https://leetcode.com/problems/search-in-rotated-sorted-array/
* https://www.spoj.com/problems/CURDPROD/
*/

int bsearch(vector<int> v, int target) {
    int l = 0, r = sz(v) - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        debug2(l, r);
        debug(mid);
        if (v[mid] == target) return mid;
        else if (v[mid] < target) {
            l = mid + 1;
        } else r = mid - 1;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    int v[] = { 1, 3, 5, 9, 10, 5124, 5675135 };
    int i = bsearch(vector<int>(&v[0], &v[0] + 7), 10);
    if (i != -1) {
        cout << "10 found at position : " << i << endl;
    } else {
        cout << "10 not found" << endl;
    }
}
