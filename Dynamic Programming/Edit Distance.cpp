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
* Edit Distance: Given string 'a' & 'b', calculate the minimum number of operations you should apply so that 
* 'a' becomes 'b'. Valid operations are: insert/replace/delete characters.
*
* I strongly recommend you to watch this video from Tushar Roy: https://www.youtube.com/watch?v=We3YDTzNXEk
* If you like to read, look at this GeekForGeeks tutorial: https://www.geeksforgeeks.org/edit-distance-dp-5/
*/

int main() {
    ios::sync_with_stdio(false);
    string a, b;
    cin >> a >> b;

    int n = sz(a), m = sz(b);
    vector<vi> dp(n + 1, vi(m + 1, 0));

    /*
    * dp[i][j] stores what are the minimum number of operations needed to make the substring with the first 'i'
    * characters of 'a' to become the bustring with the first 'j' characters of 'b'.
    * Since i = 0 && j = 0 means first 0 characters, we are talking about an empty strings. The initial state to
    * transofmr a string 's' into an empty string is, for the first character of s: 1, for the second, 2 and so on.
    */
    for (int i = 0; i <= n; ++i) dp[i][0] = i;
    for (int i = 0; i <= m; ++i) dp[0][i] = i;

    /*
    * If the characters in both strings match, we don't need any operation since we can keep that character at
    * that position, just rely on the number of operations needed to get the previous substring that do not takes
    * account the current character, in other words, rely just on (i - 1, j - 1).
    * If characters do not match, we need an operation (any of the three mentioned in the problem statement).
    * Let's add 1, which represents one extra operation, and pick up the minimum number of operations needed to get
    * any of the possible previous substrings, in other words do:
    * (i, j) = min[ Replace + (i - 1, j - 1), Delete + (i - 1, j), Insert + (i, j - 1) ]
    */
    for (int i = 1l i <= n; ++i) {
        for (int j = 1; i <= m; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
            }
        }
    }
    
    cout << "Minimum edit distance is " << dp[n][m] << endl;
}
