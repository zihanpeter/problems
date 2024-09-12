#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e5 + 5;
int n, k, ans, rudu[N], deep[N];
bool vis[N];
vector<int> g[N];
queue<int> q;
void topoSort() {
    for (int i = 1; i <= n; ++i) {
        if (!rudu[i]) 
            q.push(i);
        deep[i] = 1;
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        // cout << x << endl;
        for (int i = 0; i < g[x].size(); ++i) {
            int y = g[x][i];
            if (y == 1) 
                continue;
            if (deep[x] >= k) { 
                ++ans;
            } else 
                deep[y] = deep[y] > deep[x] + 1 ? deep[y] : deep[x] + 1;
            rudu[y]--;
            if (!rudu[y]) 
                q.push(y);
        }
    }
}
int main() {
    freopen("kingdoor.in","r",stdin);
    scanf("%d%d", &n, &k);
    int t;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &t);
        if (i == 1 && t != 1) {
            ++ans;
        }
        if (i != 1) {
            g[i].push_back(t);
            ++rudu[t];
        } else {
            ++rudu[1];
        }
    }
    topoSort();
    printf("%d", ans);
    return 0;
}