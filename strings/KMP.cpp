#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define mii map<int, int>
#define vi vector<int>
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
#define debug(x) cout<<#x<<" : "<<x<<endl
#define debug2(x,y) cout<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cout<<"hola papa"<<endl
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const int N = 10000;

vi lps(N);

/*
* This method will compute lps array.
* LPS Array indicates longest proper prefix (ignoring full string) which is also a suffix
*/
void buildLPSArray(string pattern) {
    lps[0] = -1;
    int i = 0, j = -1;
    while (i < sz(pattern)) {
        while (j >= 0 && lps[i] != lps[j]) {
            j = lps[j];
        }
        lps[++i] = ++j;
    }
}

/*
* KMP Search will use LPS Array to reset the value of j.
* j must be reseted using LPS Array in order to avoid 
* unnecessary iterations.
* j indicate current index for pattern.
* i indicate current index for text.
* It is easy to note here that the complexity of this algorithm 
* is O(n) where n is the length of text
*/
vi kmp(string pattern, string text) {
    vi matchings;
    int i = 0, j = 0;
    while (i < sz(text)) {
        if (text[i] == pattern[j] || j < 0) {
            ++i, ++j;
            if (j == sz(pattern)) {
                matchings.pb(i - j);
                j = lps[j];
            }
        } else if (j >= 0) {
            j = lps[j];
        }
    }
    return matchings;
}

string pattern, text;

int main() {
    cout << "Pattern : ";
    cin >> pattern;
    buildLPSArray(pattern);
    cout << "\nLook for pattern in this text : ";
    while (cin >> text) {
        vi matchings = kmp(pattern, text);
        if (sz(matchings) == 0) {
            cout << "Pattern not found in this text";
        } else {
            for (int i = 0; i < sz(matchings); ++i) {
                cout << "* Pattern was found at index : " << matchings[i] << "\n";
            }
        }
        cout << "\nLook for pattern in this text : ";
    }
}

