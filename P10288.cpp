#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
const int N = 1e5 + 5;

int T, n, a[N], q, cnt;
vector<int> v[N];
map<int, int> mp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> T;
	while (T--) {
		cnt = 0;
		for (int i = 0; i < N; ++i) v[i].clear();
		mp.clear();
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			mp[a[i]] = ++cnt;
		}
		for (int i = 1; i <= n; ++i) v[mp[a[i]]].push_back(i);
		cin >> q;
		int l, r, x;
		while (q--) {
			cin >> l >> r >> x;
			cout << upper_bound(v[mp[x]].begin(), v[mp[x]].end(), r) - lower_bound(v[mp[x]].begin(), v[mp[x]].end(), l) << '\n';
		}
	}
	return 0;
}
