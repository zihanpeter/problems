#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, MOD = 1e9 + 7;
int n, m, c1[N], c2[N];
struct node {
    int opt, l, r;
} nds[N];

int main() {
    scanf("%d%d", &n, &m);  
    for (int i = 1; i <= m; ++i) scanf("%d%d%d", &nds[i].opt, &nds[i].l, &nds[i].r);
    for (int i = m; i; --i) {
        c1[i] = (c1[i] + c1[i + 1]) % MOD;
        if (nds[i].opt == 2) {
            c1[nds[i].r] = (c1[nds[i].r] + c1[i] + 1) % MOD;
            c1[nds[i].l - 1] = (c1[nds[i].l - 1] - c1[i] - 1 + MOD) % MOD;
        }
    }
    for (int i = 1; i <= m; ++i) if (nds[i].opt == 1) {
        c2[nds[i].l] = (c2[nds[i].l] + c1[i] + 1) % MOD;
        c2[nds[i].r + 1] = (c2[nds[i].r + 1] - c1[i] - 1 + MOD) % MOD;
    }
    for (int i = 1; i <= n; ++i) c2[i] = (c2[i - 1] + c2[i]) % MOD;
    for (int i = 1; i <= n; ++i) printf("%d ", c2[i]);
    return 0;
}