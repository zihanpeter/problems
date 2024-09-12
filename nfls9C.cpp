#include <iostream>
using namespace std;
const int N = 2e5 + 5, SZ = 500;
int n, k[N], m, nxt[N], cnt[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", k + i);
    for (int i = 1; i <= n; ++i) {
        nxt[i] = i;
        while (nxt[i] / SZ <= i / SZ) {
            nxt[i] = nxt[i] + k[nxt[i]];
            cnt[i]++;
            if (nxt[i] > n) {
                break;
            }
        }
    }
    int x, y, z;
    scanf("%d", &m);
    while (m--) {
        scanf("%d%d", &x, &y);
        ++y;
        if (x == 1) {
            int t = 0;
            while (y <= n) {
                t += cnt[y];
                y = nxt[y];
            }
            t += cnt[y];
            printf("%d\n", t);
        } else {
            scanf("%d", &z);
            k[y] = z;
            int i = y;
            for (int i = y / SZ * SZ + 1; i <= y; ++i) {
                nxt[i] = i;
                cnt[i] = 0;
                while (nxt[i] / SZ <= i / SZ) {
                    nxt[i] = nxt[i] + k[nxt[i]];
                    cnt[i]++;
                    if (nxt[i] > n) {
                        break;
                    }
                }
            }
        }
    }
    return 0;
}