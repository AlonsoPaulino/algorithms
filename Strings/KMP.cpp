#include <bits/stdc++.h>
#define MAX 10000
using namespace std;

string p, t;
int lp, lt, b[MAX];

void kmpPreprocess() {
	b[0] = -1;
	int i = 0, j = -1;
	while (i < lp) {
		while (j >= 0 && p[i] != p[j]) j = b[j];
		i++, j++;
		b[i] = j;
	}
}

void kmpSearch(){
	int i = 0, j = 0;
	while (i < lt) {
		if (t[i] == p[j] || j < 0) {
			i++, j++;
			if (j == lp) {
				cout << "String matched in index -> " << i - j << endl;
				j = b[j];
			}
		} else {
			if (j >= 0) {
				j = b[j];
			}
		}
	}
}

int main() {
	getline(cin, t);
	getline(cin, p);
	lt = t.size();
	lp = p.size();
	kmpPreprocess();
	kmpSearch();
}
