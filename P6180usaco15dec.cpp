// USACO 2015 December Contest, Silver
// Problem 3. Breed Counting
#include <iostream>
using namespace std;
const int N = 1e5 + 5;
int n, q, ar[N], a[N], b[N], c[N];

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) scanf("%d", ar + i);
    for (int i = 1; i <= n; ++i) {
        a[i] = a[i - 1], b[i] = b[i - 1], c[i] = c[i - 1];
        if (ar[i] == 1) ++a[i];
        if (ar[i] == 2) ++b[i];
        if (ar[i] == 3) ++c[i];
    }
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d %d %d\n", 
            a[r] - a[l - 1], b[r] - b[l - 1], c[r] - c[l - 1]);
    }
    return 0;
}