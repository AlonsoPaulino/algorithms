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
#define MAX 2 * 100001
#define vll vector<ll>
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int n, q, l, r;

/* This method will retrieve the sum from index 0 to x.
To do this, first we initialize sum = 0, and starting from index x,
we are going to get the parent of x in the Fenwick tree, because
that node contains the sum of another range between 0 and x. Repeat
this process until x == 0, which is the parent of the Fenwick tree. */
int read(vi &bit, int x) {
  ll sum = 0;
  while (x > 0) {
    sum += bit[x];
    //1. 2's complement
    //2. Original number & 2's complement
    //3. Substract the result from the step 2 to the original number.
    x -= (x & -x);
  }
  return sum;
}

/* Modify will update the Fenwick tree when we modify any element of our
original array. First we have to get all nodes that are going to be affected.
To get the next node affected, we follow similar steps as in read method. Starting
from x until the end of the array, we are going to add the element that we want
to add in position x, to all nodes in the Fenwick Tree that must be affected. */
void modify(vi &bit, int x, int add) {
  while (x < sz(bit)) {
    bit[x] += add;
    //1. 2's complement
    //2. Original number & 2's complement
    //3. Add the result from the step 2 to the original number.
    x += (x & -x);
  }
}

int main() {
  //n: number of elements, q: number of queries
  cin >> n >> q;
  vi v(n), bit(n + 1, 0);
  //read the elements
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    //modify the fenwick tree adding v[i] to the element located at position i + 1
    modify(bit, i + 1, v[i]);
  }
  for (int i = 0; i < q; ++i) {
    cin >> l >> r;
    cout << "Sum from index " << l << " to index " << r << " is -> " << read(bit, r + 1) - read(bit, l) << "\n";
  }
}
