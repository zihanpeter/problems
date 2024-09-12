#include <iostream>
#include <algorithm>
using namespace std;
int n, b;
struct node {
    int p, s;
} nds[1005];

bool cmp(node x, node y) {
    if (x.p + x.s == y.p + y.s) return x.p < y.p;
    return x.p + x.s < y.p + y.s;
}

int main() {
    scanf("%d%d", &n, &b);
    for (int i = 1; i <= n; ++i) scanf("%d%d", &nds[i].p, &nds[i].s);
    sort(nds + 1, nds + n + 1, cmp);
    int sum = 0, ans = 0;
    for (int i = 1; i <= n; ++i) {
        ++ans;
        sum += nds[i].p + nds[i].s;
        if (sum > b) {
            sum -= nds[i].p / 2;
            if (sum > b) --ans;
            break;
        }
    }
    printf("%d", ans);
    return 0;
}