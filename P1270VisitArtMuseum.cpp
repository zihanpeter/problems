#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 5;
struct node {
    int t, n;
} info[N];
int t, dp[N][N];
int dfsResolve(int x, int y) {
    if (y <= 0) 
        return 0;
    if (dp[x][y]) 
        return dp[x][y];
    if (info[x].n != 0) 
        return dp[x][y] = min(y / 5, info[x].n);
    int ans = max(dfsResolve(2 * x, y - info[2 * x].t), dfsResolve(2 * x + 1, y - info[2 * x + 1].t));
    for (int k = 0; k <= y - info[2 * x].t - info[2 * x + 1].t; ++k) {
        ans = max(ans, dfsResolve(2 * x, k) + dfsResolve(2 * x + 1, y - info[2 * x].t - info[2 * x + 1].t - k));
    }
    return dp[x][y] = ans;
}
void input(int x) {
    int t, n;
    cin >> t >> n;
    info[x].t = 2 * t;
    info[x].n = n;
    if (info[x].n == 0) {
        input(2 * x);
        input(2 * x + 1);
    }
}
int main() {
    cin >> t;
    input(1);
    cout << dfsResolve(1, t - info[1].t - 1);
    return 0;
}