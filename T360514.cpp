#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, q, a[N], s[N];

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
    while (q--) {
        int b;
        scanf("%d", &b);
        int ans = lower_bound(s + 1, s + n + 1, b) - s;
        if (ans > n) ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}