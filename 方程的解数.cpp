#include <iostream>
#include <cmath>
using namespace std;
int n, m, ans;
int k[10], p[10];
void dfs(int t, int sum) {
    if (t == n + 1) {
        if (sum == 0) ++ans;
        return;
    }
    for (int i = 1; i <= m; ++i) {
        dfs(t + 1, sum + pow(i, p[t]) * k[t]);
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", k + i, p + i);
    }
    dfs(1, 0);
    printf("%d", ans);
    return 0;
}