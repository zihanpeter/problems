#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e5 + 5;
int n, m, c, s[N], rudu[N];
struct node {
    int p, w;
};
vector<node> g[N];
void topoSort() {
    queue<int> q;
    for (int i = 1; i <= n; ++i) 
        if (!rudu[i]) 
            q.push(i);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < g[x].size(); ++i) {
            int y = g[x][i].p;
            int w = g[x][i].w;
            s[y] = s[y] > s[x] + w ? s[y] : s[x] + w;
            --rudu[y];
            if (!rudu[y])
                q.push(y);
        }
    }
    return;
}
int main() {
    scanf("%d%d%d", &n, &m, &c);
    for (int i = 1; i <= n; ++i) 
        scanf("%d", s + i);
    int a, b, x;
    for (int i = 1; i <= c; ++i) {
        scanf("%d%d%d", &a, &b, &x);
        ++rudu[b];
        g[a].push_back(node{b, x});
    }
    topoSort();
    for (int i = 1; i <= n; ++i) 
        printf("%d\n", s[i]);
    return 0;
}