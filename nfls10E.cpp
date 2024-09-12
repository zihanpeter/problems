#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e7 + 10, sz = 500;
int n, q, a[N], ans[N], cnt[N], res, prime[N];
bool tong[N];
struct node {
	int l, r, num;
} s[N];
struct factor {
	int x, y;
};
vector<factor> f[N];
bool cmp(node x, node y) {
	if (x.l / sz == y.l / sz) 
		return (x.l / sz & 1) ? x.r < y.r : x.r > y.r;
	return x.l < y.l;
}
void add(int x) {
	for (int i = 0; i < f[x].size(); ++i) {
		if (cnt[f[x][i].x] % 3) --res;
		cnt[f[x][i].x] += f[x][i].y;
		if (cnt[f[x][i].x] % 3) ++res;
	}
}
void del(int x) {
	for (int i = 0; i < f[x].size(); ++i) {
		if (cnt[f[x][i].x] % 3) --res;
		cnt[f[x][i].x] -= f[x][i].y;
		if (cnt[f[x][i].x] % 3) ++res;
	}
}
inline int read() {  
    int x = 0, f = 1;  
    char ch = getchar();  
    while (ch < '0' || ch > '9') {  
        if (ch == '-') f = -1;  
        ch = getchar();
    }  
    while (ch >= '0' && ch <= '9') {  
        x = x * 10 + ch - '0';  
        ch = getchar();
    }  
    return x * f;  
}
int main() {
	n = read(), q = read();
	int maxf = -0x3f3f3f3f;
	for (int i = 1; i <= n; ++i) a[i] = read(), maxf = max(maxf, a[i]);
	for (int i = 1; i <= q; ++i) {
		s[i].l = read(), s[i].r = read();
		s[i].num = i;
	}
	int cnt2 = 0;
	for (int i = 2; i <= maxf; ++i) {
		if (!tong[i]) prime[++cnt2] = i;
		for (int j = 1; j <= cnt2 && i * prime[j] <= maxf; ++j) {
			tong[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
	int t, cnt;
	for (int i = 1; i <= n; ++i) {
		t = a[i];
		if (t == 1) continue;
		for (int j = 1; prime[j] * prime[j] <= t; ++j) {
			cnt = 0;
			while (!(t % prime[j])) {
				++cnt;
				t /= prime[j];
			}
			if (cnt) f[i].push_back(factor{prime[j], cnt});
		}
		if (t > 1) f[i].push_back(factor{t, 1});
	}
	sort(s + 1, s + q + 1, cmp);
	int l = 1, r = 0;
	for (int i = 1; i <= q; ++i) {
		while (l > s[i].l) add(--l);
		while (l < s[i].l) del(l++);
		while (r < s[i].r) add(++r);
		while (r > s[i].r) del(r--);
		ans[s[i].num] = !res;
	}
	for (int i = 1; i <= q; ++i) 
		ans[i] ? printf("Yes\n") : printf("No\n");
	return 0;
}