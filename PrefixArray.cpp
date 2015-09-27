#include <bits/stdc++.h>
using namespace std;

int l;
string s;

void prefix_array(vector<int> &v) {
	v[0] = -1;
	int i = 0, j = -1;
	while (i < l) {
		while (j >= 0 && s[i] != s[j]) j = b[j];
		i++, j++;
		v[i] = j;
	}
}

int main() {
	while (cin >> s) {
		l = s.size();
		vector<int> b(l);
		prefix_array(b);
		
		for (int i = 0; i < l; ++i) {
			cout << b[i] << " ";
		}

		endl(cout);
	}
}