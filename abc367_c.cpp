#include <bits/stdc++.h>
using namespace std;
int n, k, r[10], ans[10], sum;
void dfs(int t) {
    if (t == n + 1) {
        if (sum % k == 0) {
            for (int i = 1; i <= n; ++i) 
                printf("%d ", ans[i]);
            printf("\n");
        }
        return;
    }
    for (int i = 1; i <= r[t]; ++i) {
        ans[t] = i;
        sum += i;
        dfs(t + 1);
        sum -= i;
    }
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", r + i);
    dfs(1);
    return 0;
}