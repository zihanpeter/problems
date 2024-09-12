#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5, SIZE = 330;
int n, L[N], R[N], q, cnt[N][SIZE], cha[N];
ll a[N], sum[SIZE], tree[N];

int lowbit(int x) { return x & -x; }

void add(int x, ll v) {
	while (x <= n) {
		tree[x] += v;
		x += lowbit(x);
	}
}

ll find(int x) {
	ll sum = 0;
	while (x) {
		sum += tree[x];
		x -= lowbit(x);
	}
	return sum;
}

void build() {
	for (int i = 1; i <= n; ++i) {
		int k = i / SIZE;
		sum[k] += find(R[i]) - find(L[i] - 1);
	}
	for (int i = 0; i <= n / SIZE; ++i) {
		memset(cha, 0, sizeof(cha));
		for (int j = i * SIZE; j < (i + 1) * SIZE && j <= n; ++j) 
			++cha[L[j]], --cha[R[j] + 1];
		for (int j = 1; j <= n; ++j) 
			cha[j] += cha[j - 1];
		for (int j = 1; j <= n; ++j) 
			cnt[j][i] = cha[j];
	}
}

void update(int x, ll y) {
	ll c = y - a[x];
	add(x, c);
	for (int i = 0; i <= n / SIZE; ++i) sum[i] += cnt[x][i] * c;
	a[x] = y;
}

ll query(int l, int r) {
	int kl = l / SIZE, kr = r / SIZE;
	ll ans = 0;
	if (kl == kr) {
		for (int i = l; i <= r; ++i) 
			ans += find(R[i]) - find(L[i] - 1);
	} else {
		for (int i = l; i < (kl + 1) * SIZE; ++i) 
			ans += find(R[i]) - find(L[i] - 1);
		for (int i = kr * SIZE; i <= r; ++i) 
			ans += find(R[i]) - find(L[i] - 1);
		for (int i = kl + 1; i < kr; ++i) 
			ans += sum[i];
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", a + i);
		add(i, a[i]);
	}
	for (int i = 1; i <= n; ++i) scanf("%d%d", L + i, R + i);
	build();
	scanf("%d", &q);
	int opt, x, y;
	while (q--) {
		scanf("%d%d%d", &opt, &x, &y);
		if (opt == 1) update(x, y);
		else printf("%lld\n", query(x, y));
	}
	return 0;
}
