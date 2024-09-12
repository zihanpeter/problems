#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int mod = 10007;
int n, w[N], ansMax = -0x7fffffff, ansSum;
vector<int> g[N];
int main() {
    scanf("%d", &n);
    int u, v;
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) 
        scanf("%d", w + i);
    for (int i = 1; i <= n; ++i) {
        int maxFirst = -0x7fffffff, maxSecond = -0xfffffff;
        long long sum = 0, realSum = 0;
        for (int j = 0; j < g[i].size(); ++j) {
            sum += w[g[i][j]];
            realSum -= w[g[i][j]] * w[g[i][j]];
            if (w[g[i][j]] > maxFirst) {
                maxSecond = maxFirst;
                maxFirst = w[g[i][j]];
            } else if (w[g[i][j]] > maxSecond) {
                maxSecond = w[g[i][j]];
            }
        }
        realSum = realSum + sum * sum;
        ansSum = ((ansSum % mod) + (realSum % mod)) % mod;
        ansMax = max(ansMax, maxFirst * maxSecond);
    }
    printf("%d %d", ansMax, ansSum);
    return 0;
}