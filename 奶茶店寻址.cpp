#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e6 + 5;
const long long mod = 1e9 + 7;
struct node {
    int x, y;
} side[1000005];
int n, m, rudu1[N], rudu2[N], leftNum[N], rightNum[N];
vector<int> g1[N], g2[N];
queue<int> q1, q2;
void topo1() {
    for (int i = 1; i <= n; ++i) 
        if (rudu1[i] == 0) q1.push(i);
    while (!q1.empty()) {
        int x = q1.front();
        q1.pop();
        for (int i = 0; i < g1[x].size(); ++i) {
            int y = g1[x][i];
            leftNum[y] = ((leftNum[y])%mod + (leftNum[x])%mod % mod);
            rudu1[y]--;
            if (rudu1[y] == 0) q1.push(y);
        }
    }
}
void topo2() {
    for (int i = 1; i <= n; ++i) 
        if (rudu2[i] == 0) q2.push(i);
    while (!q2.empty()) {
        int x = q2.front();
        q2.pop();
        for (int i = 0; i < g2[x].size(); ++i) {
            int y = g2[x][i];
            rightNum[y] = ((rightNum[y])%mod + (rightNum[x])%mod % mod);
            rudu2[y]--;
            if (rudu2[y] == 0) q2.push(y);
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    int x, y;
    for (int i = 1; i <= n; ++i) {
        leftNum[i] = 1; rightNum[i] = 1;
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &x, &y);
        side[i].x = x; side[i].y = y;
        ++rudu1[y]; ++rudu2[x];
        g1[x].push_back(y);
        g2[y].push_back(x);
    }
    topo1();
    topo2();
    for (int i = 1; i <= m; ++i) 
        printf("%lld\n", 1ll * ((leftNum[side[i].x]%mod) * (rightNum[side[i].y]%mod))%mod);
    return 0;
}