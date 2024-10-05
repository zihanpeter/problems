#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5e3 + 5;
int n, t;
struct node {
    int x, p;
} a[N];
bool cmp(node x, node y) {
    if (x.x == y.x) return x.p < y.p;
    return x.x < y.x;
}
int main() {
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i].x);
        a[i].p = i;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n - 2; ++i) {
        int j = i + 1, k = n;
        while (j < k) {
            if (a[i].x + a[j].x + a[k].x == t) {
                printf("%d %d %d", a[i].p, a[j].p, a[k].p);
                return 0;
            } else if (a[i].x + a[j].x + a[k].x < t) ++j;
            else if (a[i].x + a[j].x + a[k].x > t) --k;
        }
    }
    printf("IMPOSSIBLE");
    return 0;
}