#include <iostream>
#define int long long
using namespace std;
int v, n, t, f[305];
int w[305][305], c[305][305];

signed main() {
    scanf("%lld%lld%lld", &v, &n, &t);
    for (int i = 1; i <= n; ++i) {
        int ww, cc, p;
        scanf("%lld%lld%lld", &ww, &cc, &p);
        w[p][++w[p][0]] = ww;
        c[p][++c[p][0]] = cc;
    }
    for (int i = 1; i <= t; ++i) 
        for (int j = v; j >= 0; --j) 
            for (int k = 1; k <= w[i][0]; ++k) 
                if (j >= w[i][k]) 
                    f[j] = max(f[j], f[j - w[i][k]] + c[i][k]);
    printf("%lld", f[v]);
    return 0;
}