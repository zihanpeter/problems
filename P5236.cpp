#include <iostream>
using namespace std;
const int N = 2e4 + 5;
int n, m, q;
int cnt, head[N], to[N], nxt[N], wi[N];

void add(int u, int v, int w) {
    nxt[++cnt] = head[u]; head[u] = cnt; to[cnt] = v; wi[cnt] = w;
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    int u, v, w;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    
    return 0;
}