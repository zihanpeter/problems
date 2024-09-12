#include <iostream>
using namespace std;
const int N = 1e3 + 5, M = 1e6 + 5;
int n, m, va[M], vb[M], suma, sumb, t, ans;
int main() {
    scanf("%d%d", &n, &m);
    int t1, t2, l = 0, r = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &t1, &t2);
        suma += t2;
        l = r + 1; r = l + t2 - 1;
        va[l] += t1, va[r + 1] -= t1;
    }
    l = 0, r = 0;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &t1, &t2);
        sumb += t2;
        l = r + 1; r = l + t2 - 1;
        vb[l] += t1, vb[r + 1] -= t1;
    }
    t = max(suma, sumb);
    for (int i = 1; i <= suma; ++i) va[i] += va[i - 1];
    for (int i = 1; i <= sumb; ++i) vb[i] += vb[i - 1];
    int disa = 0, disb = 0, flag = -1;
    for (int i = 1; i <= t; ++i) {
        disa += va[i]; disb += vb[i];
        if (disa > disb && flag != 1) {
            flag = 1;
            ++ans;
        }
        if (disb > disa && flag != 0) {
            flag = 0;
            ++ans;
        }
    }
    printf("%d", ans ? ans - 1 : ans);
    return 0;
}