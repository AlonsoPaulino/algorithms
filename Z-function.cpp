#include <bits/stdc++.h>
using namespace std;

string s;
int n;

void z_function(vector<int> &z) {
	int l, r, k;
	z[0] = 0;
	l = r = 0;
	
	for (int i = 1; i < n; ++i) {
		if (i  > r) {
			l = r = i;
			while (r < n && (s[r - l] == s[r])) r++;
			z[i] = r - l;
			r--;
		} else {
			k = i - l;
			if (z[k] < r - i + 1) {
				z[i] = z[k];
			} else {
				l = i;
				while (r < n && (s[r - l] == s[r])) r++;
				z[i] = r - l;
				r--;
			}
		}
	}
}

int main() {
	while (cin >> s) {
		n = s.size();
		vector<int> z(n);
		z_function(z);

		for (int i = 0; i < n; ++i) {
			cout << z[i] << " ";
		}
	}
}