#include <bits/stdc++.h>
using namespace std;
const int N = 300 + 5;
int n, m, s[N], l[N], r[N], lxt[N], dp[N][N];
int dfsResolve(int i, int j) {
    if (i == 0 || j == 0) 
        return dp[i][j] = 0;
    if (dp[i][j])
        return dp[i][j];
    int ans = dfsResolve(r[i], j);
    for (int k = 0; k < j; ++k) 
        ans = max(ans, s[i] + dfsResolve(l[i], k) + dfsResolve(r[i], j - k - 1));
    return dp[i][j] = ans;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k >> s[i];
        if (l[k] == 0) {
            l[k] = i;
        } else {
            r[lxt[k]] = i;
        }
        lxt[k] = i;
    }
    cout << dfsResolve(l[0], m);
    return 0;
}