#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, ans, a[N];
int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) 
		cin >> a[i];
	for (int i = 1; i <= n; ++i) 
		for (int j = i; j <= n; ++j) 
			if (a[i] > a[j]) {
				++ans;
				swap(a[i], a[j]);
			}
	cout << ans << endl;
	return 0;
} 
