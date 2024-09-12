#include <iostream>
#include <set>
using namespace std;
const int N = 5e5 + 5, SIZE = 750, INF = 0x3f3f3f3f;
int n, q;
long long a[N], lazy[SIZE];
multiset<long long> s[SIZE];

void build() {
	int k;
	for (int i = 1; i <= n; ++i) {
		k = i / SIZE;
		s[k].insert(a[i]);
	}
}

void update(int l, int r, int x) {
	int kl = l / SIZE, kr = r / SIZE;
	if (kl == kr) 
		for (int i = l; i <= r; ++i) {
			s[kl].erase(s[kl].find(a[i]));
			a[i] += x;
			s[kl].insert(a[i]);
		}
	else {
		for (int i = l; i < (kl + 1) * SIZE; ++i) {
			s[kl].erase(s[kl].find(a[i]));
			a[i] += x;
			s[kl].insert(a[i]);
		}
		for (int i = kr * SIZE; i <= r; ++i) {
			s[kr].erase(s[kr].find(a[i]));
			a[i] += x;
			s[kr].insert(a[i]);
		}
		for (int i = kl + 1; i < kr; ++i) lazy[i] += x;
	}
}

int query(int y) {
	int minf = INF, maxf = -INF;
	for (int i = 0; i <= n / SIZE; ++i) 
		if (s[i].count(y - lazy[i])) {
			for (int j = i * SIZE; j < (i + 1) * SIZE; ++j) {
				if (a[j] + lazy[i] == y) {
					minf = j;
					break;
				}
			}
			break;
		}
	if (minf == INF) return -1;
	for (int i = n / SIZE; i >= 0; --i) {
		if (s[i].count(y - lazy[i])) {
			for (int j = (i + 1) * SIZE - 1; j >= i * SIZE; --j) {
				if (a[j] + lazy[i] == y) {
					maxf = j;
					break;
				}
			}
			break;
		}
	}
	return maxf - minf; 

}

signed main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
	build();
	int opt, l, r, x, y;
	while (q--) {
		scanf("%d", &opt);
		if (opt == 1) {
			scanf("%d%d%d", &l, &r, &x);
			update(l, r, x);
		} else {
			scanf("%d", &y);
			printf("%d\n", query(y));
		}
	}
	return 0;
}