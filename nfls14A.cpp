#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 5e4 + 205, BASE = 127;
string s;
int n, pos[N];
ull h[N], b[N];
void calc_hash() {
	h[0] = 1;
	for (int i = 1; i < s.length(); ++i) 
		h[i] = h[i - 1] * BASE + s[i];
}
ull check(int l, int r) { return h[r] - h[l - 1] * b[r - l + 1]; }
int main() {
	freopen("nfls14A.in", "r", stdin);
	cin >> s >> n;
	s = " " + s;
	char opt, c;
	int x, y;
	for (int i = 1; i < s.length(); ++i) pos[i] = i;
	calc_hash();
	b[0] = 1;
	for (int i = 1; i <= 5e4 + 200; ++i) b[i] = b[i - 1] * BASE;
	while (n--) {
		cin >> opt;
		if (opt == 'I') {
			cin >> c >> x;
			for (int i = 1; i <= s.length(); ++i) 
				if (pos[i] >= x) 
					++pos[i];
			s.insert(x, 1, c);
			calc_hash();
		} else {
			cin >> x >> y;
			x = pos[x], y = pos[y];
			int l = 1, r = s.length() - max(x, y), ans = 0;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (check(x, x + mid - 1) == check(y, y + mid - 1)) 
					ans = mid, l = mid + 1;
				else r = mid - 1;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}