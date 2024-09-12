#include <bits/stdc++.h>
using namespace std;
int tong[15];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = n; i <= m; ++i) {
		int t = i;
		while (t) {
			++tong[t % 10];
			t /= 10;
		}
	}
	for (int i = 0; i <= 9; ++i) cout << tong[i] << ' ';
	return 0;
}