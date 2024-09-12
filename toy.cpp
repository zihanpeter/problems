#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, k, ans;
int a[N], b[N];
int main() {
    freopen("toy.in", "r", stdin);
    freopen("toy.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        int t;
        for (int j = 1; j <= a[i]; ++j) {
            scanf("%d", &t);
            b[i] |= (1 << (t - 1));
        }
    }
    for (int i = 0; i < (1 << k); ++i) {
        int cnt = 0;
        for (int j = 1; j <= k; ++j) 
            if ((i >> (j - 1)) & 1) 
                ++cnt;
        if (cnt > m) continue;
        int cnt2 = 0;
        for (int j = 1; j <= n; ++j) {
            if ((i & b[j]) == b[j]) 
                ++cnt2;
        }
        ans = max(ans, cnt2);
    }
    printf("%d", ans);
	return 0;
}