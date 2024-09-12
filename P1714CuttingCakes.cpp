#include <iostream>
#include <deque>
using namespace std;
const int N = 5e5 + 5;
int n, m, dp[N], sum[N];
deque<int> q;
int main() {
    cin >> n >> m;
    int t;
    for (int i = 1; i <= n; ++i) {
        cin >> t;
        sum[i] = sum[i - 1] + t;
    }
    for (int i = 0; i <= n; ++i) {
        while (!q.empty() && sum[q.back()] > sum[i])
            q.pop_back();
        while (!q.empty() && q.front() < i - m + 1)
            q.pop_front();
        q.push_back(i);
        dp[i + 1] = sum[i + 1] - sum[q.front()];
    }
    int ans = -0x3f3f3f3f;
    for (int i = 1; i <= n; ++i) 
        ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}