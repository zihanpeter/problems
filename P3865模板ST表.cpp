#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, f[N][50];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) 
        scanf("%d", &f[i][0]);
    int k = log2(n);
    for (int j = 1; j <= k; ++j) {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }
    int l, r;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &l, &r);
        k = log2(r - l + 1);
        printf("%d\n", max(f[l][k], f[r - (1 << k) + 1][k]));
    }
    return 0;
}
