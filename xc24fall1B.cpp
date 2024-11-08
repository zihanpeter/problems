// Gold Mining
#include <iostream>
using namespace std;
const int N = 1e6 + 5;
int n, m, gl[N], ml[N];
struct node {
    int x, y;
} go[N], ma[N];

bool cmp(node x, node y) {
    if (x.x == y.x) return x.y < y.y;
    return x.x < y.x;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d%d", &go[i].x, &go[i].y);
    for (int i = 1; i <= m; ++i) scanf("%d%d", &ma[i].x, &ma[i].y);
    sort(go + 1, go + n + 1, cmp);
    sort(ma + 1, ma + m + 1, cmp);
    
    for (int i = 1; i <= m; ++i) {
        
    }
    return 0;
}