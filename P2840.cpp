#include <iostream>
using namespace std;
const int N = 1e4 + 5, MOD = 1e9 + 7;
int n, w, a[N], f[N];

int main() {
    scanf("%d%d", &n, &w);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    f[0] = 1;
    for (int i = 1; i <= w; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i >= a[j]) f[i] = (f[i] + f[i - a[j]]) % MOD;
        }
    }
    printf("%d", f[w]);
    return 0;
}

