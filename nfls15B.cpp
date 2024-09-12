#include <bits/stdc++.h>
using namespace std;
const int N = 30;
int n, a[N], sum, ans;
char s[105];


void dfs(int t, int x) {
    if (t == n + 1) {
        if (x == sum) ++ans;
        return;
    }
    dfs(t + 1, x | a[t]);
    dfs(t + 1, x);
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < 26; ++i) sum |= 1 << i;
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s);
        int len = strlen(s);
        for (int j = 0; j < len; ++j) a[i] |= 1 << s[j] - 'a';
    }
    dfs(1, 0);
    printf("%d", ans);
    return 0;
}