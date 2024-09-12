#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
const int N = 2e5 + 5;
int n, k, ans;
struct node {
    int x, y, c;
} nds[N];
int temp[N], b[N];
set<int> s[N];

int lowbit(int x) {
    return x & -x;
}

void add(int k, int x) {
    while (k <= n) {
        b[k] += x;
        k += lowbit(k);
    }
}

int find(int k) {
    int ans = 0;
    while (k >= 1) {
        ans += b[k];
        k -= lowbit(k);
    }
    return ans;
}

bool cmp(node x, node y) {
    return x.y < y.y;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        ans = 0;
        for (int i = 1; i <= n; ++i) scanf("%d%d%d", &nds[i].x, &nds[i].y, &nds[i].c);
        for (int i = 1; i <= n; ++i) temp[i] = nds[i].x;
        sort(temp + 1, temp + n + 1);
        int m = unique(temp + 1, temp + n + 1) - temp - 1;
        for (int i = 1; i <= n; ++i) nds[i].x = lower_bound(temp + 1, temp + m + 1, nds[i].x) - temp;
        sort(nds + 1, nds + n + 1, cmp);
        for (int i = 1; i <= k; ++i) {
            s[i].clear(); s[i].insert(0); s[i].insert(m + 1);
        }
        for (int i = 1; i <= n; ++i) b[i] = 0;
        for (int i = 1; i <= n; ) {
            int j = i;
            for (; j <= n && nds[i].y == nds[j].y; ++j) {
                set<int>::iterator it = s[nds[j].c].lower_bound(nds[j].x);
                int  r = *it - 1, l = *(--it);
                ans = max(ans, find(r) - find(l));
            }
            for (; i < j; ++i) {
                add(nds[i].x, 1);
                s[nds[i].c].insert(nds[i].x);
            }
        }
        int l;
        for (int i = 1; i <= k; ++i) {
            l = 0;
            for (set<int>::iterator it = ++s[i].begin(); it != s[i].end(); ++it) {
                ans = max(ans, find(*it - 1) - find(l));
                l = *it;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}