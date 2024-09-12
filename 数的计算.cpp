#include <iostream>
using namespace std;
int n, dp[1005];
int dfs(int x) {
    if (x == 1) return dp[x] = 1;
    for (int i = 1; i <= x / 2; ++i) {
        dp[x] += dfs(i);
    }
    return dp[x];
}
int main() {
    cin >> n;
    cout << dfs(n) << endl;
    return 0;
}