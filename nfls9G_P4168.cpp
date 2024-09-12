#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 4e4 + 205, M = 205,INF = 0x3f3f3f3f;
int n, m, a[N], b[N], cnt[M][N], p, con[M][M], tong1[N], tong2[N], to[N], sz, pos[N], bcnt;

void build() {
    for (int i = 1; i <= bcnt; ++i) {
        for (int j = 1; j <= p; ++j) cnt[i][j] = cnt[i - 1][j];
        for (int j = (i - 1) * sz + 1; j <= i * sz; ++j) ++cnt[i][a[j]];
    }
    for (int i = 1; i <= bcnt; ++i) {
        memset(tong1, 0, sizeof(tong1));
        int maxTime = -INF, maxNum = 0;
        for (int j = i; j <= bcnt; ++j) {
            for (int k = (j - 1) * sz + 1; k <= j * sz && k <= n; ++k) {
                if (++tong1[a[k]] >= maxTime) {
                    if (tong1[a[k]] == maxTime) maxNum = min(maxNum, a[k]);
                    else {
                        maxNum = a[k];
                        maxTime = tong1[a[k]];
                    }
                }
            }
            con[i][j] = maxNum;
        }
    }
    memset(tong1, 0, sizeof(tong1));
}

int query(int l, int r) {
    int kl = pos[l], kr = pos[r];
    if (kl == kr) {
        int maxTime = -INF, maxNum = 0;
        for (int i = l; i <= r; ++i) {
            if (a[i] == 0) continue;
            if (++tong1[a[i]] >= maxTime) {
                if (tong1[a[i]] == maxTime) maxNum = min(maxNum, a[i]);
                else {
                    maxTime = tong1[a[i]];
                    maxNum = a[i];
                }
            }
        }
        for (int i = l; i <= r; ++i) tong1[a[i]] = 0;
        return maxNum;
    } else {
        int maxTime1 = -INF, maxTime2 = -INF, maxNum1 = 0, maxNum2 = 0;
        // cout << l << ' ' << kl * sz << endl;
        for (int i = l; i <= kl * sz; ++i) 
            if (++tong1[a[i]] >= maxTime1) {
                if (tong1[a[i]] == maxTime1) maxNum1 = min(maxNum1, a[i]);
                else {
                    maxTime1 = tong1[a[i]];
                    maxNum1 = a[i];
                }
            }
        for (int i = (kr - 1) * sz + 1; i <= r; ++i) {
            // cout << i << endl;
            if (++tong2[a[i]] >= maxTime2) {
                if (tong2[a[i]] == maxTime2) maxNum2 = min(maxNum2, a[i]);
                else {
                    maxTime2 = tong2[a[i]];
                    maxNum2 = a[i];
                }
            }
        }
        // for (int i = 1; i <= n; ++i) cout << tong2[i] << ' ';
        // cout << endl;
        int t1 = maxTime1 + cnt[kr - 1][maxNum1] - cnt[kl][maxNum1] + tong2[maxNum1];
        // cout << "-----" << endl;
        // cout << cnt[kr - 1][maxNum1] << endl;
        // cout << cnt[kl][maxNum1] << endl;
        // cout << tong2[maxNum1] << endl;
        // cout << "-----" << endl;
        int t2 = tong1[con[kl + 1][kr - 1]] + cnt[kr - 1][con[kl + 1][kr - 1]] - cnt[kl][con[kl + 1][kr - 1]] + tong2[con[kl + 1][kr - 1]];
        int t3 = tong1[maxNum2] + cnt[kr - 1][maxNum2] - cnt[kl][maxNum2] + maxTime2;
        // cout << maxNum1 << ' ' << con[kl + 1][kr - 1] << ' ' << maxNum2 << endl;
        // cout << t1 << ' ' << t2 << ' ' << t3 << endl;
        for (int i = l; i <= kl * sz; ++i) tong1[a[i]] = 0;
        for (int i = (kr - 1) * sz + 1; i <= r; ++i) tong2[a[i]] = 0;
        if (t1 >= t2 && t1 >= t3) {
            if (t1 == t2 && t1 == t3) return min(maxNum1, min(maxNum2, con[kl + 1][kr - 1]));
            if (t1 == t2) return min(maxNum1, con[kl + 1][kr - 1]);
            if (t1 == t3) return min(maxNum1, maxNum2);
            return maxNum1;
        } else if (t2 >= t1 && t2 >= t3) {
            if (t1 == t2) return min(maxNum1, con[kl + 1][kr - 1]);
            if (t2 == t3) return min(con[kl + 1][kr - 1], maxNum2);
            return con[kl + 1][kr - 1];
        } else {
            if (t3 == t2) return min(maxNum2, con[kl + 1][kr - 1]);
            if (t1 == t3) return min(maxNum1, maxNum2);
            return maxNum2;
        } 
    }
}

int main() {
    freopen("nfls9G_P4168.in", "r", stdin);
    scanf("%d%d", &n, &m);
    sz = sqrt(n);
    for (int i = 1; i <= n; ++i) {
        pos[i] = (i + sz - 1) / sz;
        bcnt = max(bcnt, pos[i]);
    }
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = 1; i <= n; ++i) b[i] = a[i];
    sort(b + 1, b + n + 1);
    p = unique(b + 1, b + n + 1) - b - 1;
    int res;
    for (int i = 1; i <= n; ++i) {
        res = lower_bound(b + 1, b + p + 1, a[i]) - b;
        to[res] = a[i];
        a[i] = res;
    }
    // for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
    // cout << endl;
    build();
    // for (int i = 1; i <= bcnt; ++i) {
    //     for (int j = 1; j <= p; ++j) {
    //         cout << i << ' ' << j << ':' << cnt[i][j] << endl;
    //     }
    // }
    // cout << "----------" << endl;
    // for (int i = 1; i <= bcnt; ++i) 
    //     for (int j = i; j <= bcnt; ++j) 
    //         cout << i << ' ' << j << ':' << con[i][j] << endl;
    int l, r, x = 0;
    while (m--) {
        scanf("%d%d", &l, &r);
        l = ((l + x - 1) % n) + 1;
        r = ((r + x - 1) % n) + 1;
        if (l > r) swap(l, r);
        // cout << 'l' << l << 'r' << r << endl;
        x = to[query(l, r)];
        printf("%d\n", x);
    }
    return 0;
}
