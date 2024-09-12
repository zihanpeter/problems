#include <iostream>
#include <queue>
using namespace std;
const int N = 1e2 + 5;
int n, g[N][N], ans;
bool vis[N];
struct node {
    int x, dis;
};
bool operator > (const node &x, const node &y) {
    return x.dis > y.dis;
}
priority_queue<node, vector<node>, greater<node> > q;   
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= n; ++j) 
            cin >> g[i][j];
    int cnt = 0;
    q.push(node{1, 0});
    while (!q.empty()) {
        int idx = q.top().x;
        int dis = q.top().dis;
        q.pop();
        if (vis[idx]) continue;
        vis[idx] = true;
        ans += dis;
        cnt++;
        if (cnt == n - 1) break;
        for (int i = 1; i <= n; ++i) 
            if (!g[idx][i] && !vis[i]) 
                q.push(node{i, g[idx][i]});
    }
    cout << ans << endl;
    return 0;
}