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
* LCS: Longest Common Subsequence algorithm
*
* I strongly recommend you to watch this video! https://www.youtube.com/watch?v=NnD96abizww 
*/

int lcs(string s1, string s2) {
    int n = sz(s1), m = sz(s2);
    /*
    * Creating the vector with extra capacity just for making implementation easier.
    * Notice that doing this, we can start at position 1 and there is no need to validate 
    * whether i >= 0 or j >= 0.
    */ 
    vector< vi > dp(n + 5, vi(m + 5, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int main() {
    ios::sync_with_stdio(false);
    string a, b;
    cin >> a >> b;
    int x = lcs(a, b);
    cout << "The length of the longest common subsequence between " << a << " and " << b << " is: " << x << endl;
}
