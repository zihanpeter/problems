#include <iostream>
using namespace std;
const int N = 1e3 + 5, INF = 0x3f3f3f3f;
int n, W, w[N], t[N];
long long dp[N];

/*
sigma(t[i])/sigma(w[i])>=x/1000
sigma(t[i])>=sigma(w[i])*x/1000
sigma(t[i])*1000-sigma(w[i])*x>=0
sigma(t[i]*1000-w[i]*x)>=0
v[i]=t[i]*1000-w[i]*x
*/

bool check(int x) {
    dp[0] = 0;
    for (int i = 1; i <= W; ++i) dp[i] = -INF;
    for (int i = 1; i <= n; ++i) {
        for (int j = W; j >= 0; --j) {
            int tmp = min(W, w[i] + j);
            dp[tmp] = max(dp[tmp], dp[j] + (long long)t[i] * 1000 - (long long)w[i] * x);
        }
    }
    return dp[W] >= 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> W;
    for (int i = 1; i <= n; ++i) cin >> w[i] >> t[i];

    int l = 0, r = 1e9, ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}