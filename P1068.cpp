#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5e3 + 5;
int n, m;
struct node {
    int k, s;
} nds[N];
bool cmp(node x, node y) {
    if (x.s == y.s) return x.k < y.k;
    return x.s > y.s;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &nds[i].k, &nds[i].s);
    }
    sort(nds + 1, nds + n + 1, cmp);
    m = m * 1.5;
    
    printf("%d ", nds[m].s);
    int cnt = 0;
    for (int i = 1; i <= n; ++i) 
        if (nds[i].s >= nds[m].s) 
            ++cnt;
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; ++i) {
        printf("%d %d\n", nds[i].k, nds[i].s);
    }
    return 0;
}