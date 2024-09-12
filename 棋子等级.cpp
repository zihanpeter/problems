#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, tree[N], ans[N], tong[N];
int lowbit(int x) {
	return x & (-x);
}
void update(int x) {
	for (int i = x; i < N; i += lowbit(i)) 
		++tree[i];
}
int query(int x) {
	int ans = 0;
	for (int i = x; i >= 1; i -= lowbit(i)) 
		ans += tree[i];
	return ans;
}
int main() {
	cin >> n;
	int x, y;
	for (int i = 1; i <= n; ++i) {
		cin >> x >> y;
		update(x + 1);
		ans[i] = query(x + 1) - 1;
	}
	for (int i = 1; i <= n; ++i) {
		tong[ans[i]]++;
	}
	for (int i = 0; i < n; ++i) {
		cout << tong[i] << endl;
	}
	return 0;
}
