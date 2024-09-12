#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
const int N = 1e5 + 5;
int n, a[N], l[N], r[N];
vector<int> v[N];
void build() {
    int t = sqrt(n);
    for (int i = 1; i <= t; ++i) {
        l[i] = (i - 1) * t + 1;
        r[i] = l[i] + t - 1;
    }
    if (r[t] < n) {
        l[t + 1] = r[t] + 1;
        r[t + 1] = n;
        ++t;
    }
    for (int i = 1; i <= t; ++i) 
        for (int j = l[i]; j <= r[i]; ++j) 
            v[i].push_back(a[j]);
}
void update(int x, int y) {
    int pos = 0, cnt = 0;
    while (pos < x) 
        pos += v[++cnt].size();
    pos -= v[cnt].size() - 1;
    int i = 0;
    for (vector<int>::iterator it = v[cnt].begin(); it != v[cnt].end(); ++it) {
        if (pos + i == x) {
            v[cnt].insert(it, y);
            break;
        }
        ++i;
    }
}
int query(int x) {
    int pos = 0, cnt = 0;
    while (pos < x) 
        pos += v[++cnt].size();
    pos -= v[cnt].size() - 1;
    for (int i = 0; i < v[cnt].size(); ++i) {
        if (pos + i == x) {
            return v[cnt][i];
        }
    }
    return -1;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) 
        scanf("%d", a + i);
    build();
    int opt, l, r, c;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d%d%d", &opt, &l, &r, &c);
        if (opt == 0) {
            update(l, r);
        } else {
            printf("%d\n", query(r));
        }
    }
    return 0;
}