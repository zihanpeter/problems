#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int N = 4e5 + 5;
struct pos {
    int x, y, num;
} s[N];
int n, xl, yl, xb, yb, ans[N];
struct node {
    int x, w;
};
vector<node> g[N];
bool operator > (const node &x, const node &y) {
    return x.w > y.w;
}
priority_queue<node, vector<node>, greater<node> > q;
bool vis[N];

void dijkstra() {
    memset(ans, 0x3f, sizeof(ans));
    q.push(node{4 * n + 1, 0});
    ans[4 * n + 1] = 0;
    while (!q.empty()) {
        int x = q.top().x, w = q.top().w;
        q.pop();
        if (vis[x]) continue;
        vis[x] = true;
        ans[x] = w;
        for (int i = 0; i < g[x].size(); ++i) {
            if (!vis[g[x][i].x]) {
                q.push(node{g[x][i].x, g[x][i].w + w});
            }
        }
    }
}


bool cmp_x(pos x, pos y) {
    if (x.x == y.x) return x.y < y.y;
    return x.x < y.x;
}

bool cmp_y(pos x, pos y) {
    if (x.y == y.y) return x.x < y.y;
    return x.y < y.y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> xl >> yl >> xb >> yb;
    for (int i = 1; i <= n; ++i) {
        int tx, ty;
        cin >> tx >> ty;
        s[i].x = tx;
        s[i].y = ty;
        s[i].num = i;
    }

    sort(s + 1, s + n + 1, cmp_x);
    for (int i = 1; i < n; ++i) {
        if (s[i].x == s[i + 1].x) {
            g[s[i].num * 3].push_back(node{s[i + 1].num, 0});
            g[s[i + 1].num].push_back(node{s[i].num * 3, 0});
        }
    }

    sort(s + 1, s + n + 1, cmp_y);
    for (int i = 1; i < n; ++i) {
        if (s[i].y == s[i + 1].y) {
            g[s[i].num * 2].push_back(node{s[i + 1].num * 4, 0});
            g[s[i + 1].num * 4].push_back(node{s[i].num * 2, 0});
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        g[i].push_back(node{i * 2, 1});
        g[i * 2].push_back(node{i, 1});
        g[i].push_back(node{i * 3, 0});
        g[i * 3].push_back(node{i, 0});
        g[i].push_back(node{i * 4, 1});
        g[i * 4].push_back(node{i, 1});
        g[i * 2].push_back(node{i * 4, 0});
        g[i * 4].push_back(node{i * 2, 0});
        g[i * 2].push_back(node{i * 3, 1});
        g[i * 3].push_back(node{i * 2, 1});
        g[i * 3].push_back(node{i * 4, 1});
        g[i * 4].push_back(node{i * 3, 1});
    }

    for (int i = 1; i <= n; ++i) {
        if (s[i].x == xl) {
            g[s[i].num].push_back(node{4 * n + 1, 0});
            g[4 * n + 1].push_back(node{s[i].num, 0});
        }
        if (s[i].y == yl) {
            g[s[i].num].push_back(node{4 * n + 1, 0});
            g[4 * n + 1].push_back(node{s[i].num, 0});
        }
        if (s[i].x == xb) {
            g[s[i].num].push_back(node{4 * n + 2, 0});
            g[4 * n + 2].push_back(node{s[i].num, 0});
        }
        if (s[i].y == yb) {
            g[s[i].num].push_back(node{4 * n + 2, 0});
            g[4 * n + 2].push_back(node{s[i].num, 0});
        }
    }

    dijkstra();

    cout << ans[n * 4 + 2];
}