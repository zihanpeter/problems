#include <iostream>
#include <algorithm>
using namespace std;
int n, a[105], dis[105], f[105], rudu[105], ans;
bool tong[105];
int find(int x) {
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) f[i] = i;
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    sort(a + 1, a + n + 1);
    dis[1] = 2; dis[n] = n - 1;
    for (int i = 2; i < n; ++i) dis[i] = a[i] - a[i - 1] <= a[i + 1] - a[i] ? i - 1: i + 1;
    for (int i = 1; i <= n; ++i) {
        if (dis[i] == i - 1) {
            ++rudu[i - 1];
            int fx = find(i - 1), fy = find(i);
            if (fx != fy) f[fx] = fy;
        } else if (dis[i] == i + 1) {
            ++rudu[i + 1];
            int fx = find(i), fy = find(i + 1);
            if (fx != fy) f[fx] = fy;
        }
    }
    for (int i = 1; i <= n; ++i) if (!rudu[i]) {
        tong[find(i)] = true;
        ++ans;
    }
    for (int i = 1; i <= n; ++i) {
        if (tong[find(i)]) continue;
        tong[find(i)] = true;
        ++ans;
    }
    printf("%d", ans);
    return 0;
}