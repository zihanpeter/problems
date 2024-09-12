	#include <iostream>
	#include <string>
	using namespace std;
	const int N = 1e5 + 5, S = 400;
	int n, m, a[N], sum[505];


	int query(int l, int r) {
		int kl = l / S, kr = r / S, ans = 0;
		if (kl == kr) {
			for (int i = l; i <= r; ++i) ans += a[i];
		} else {
			for (int i = l; i < (kl + 1) * S; ++i) ans += a[i];
			for (int i = kr * S; i <= r; ++i) ans += a[i];
			for (int i = kl + 1; i < kr; ++i) ans += sum[i];
		}
		return ans;
	}

	void update(int id, int x) {
		int k = id / S;
		sum[k] -= a[id];
		sum[k] += x;
		a[id] = x;
	}
	int main() {
		ios::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			int k = i / S;
			sum[k] += a[i];
		}
		string s;
		int x, y;
		while (m--) {
			cin >> s >> x >> y;
			if (s == "Change") update(x, y);
			else cout << query(x, y) << '\n';
		}
		return 0;
	}