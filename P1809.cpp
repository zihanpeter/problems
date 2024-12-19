#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
int n, a[N], ans;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    sort(a + 1, a + n + 1);
    while (n > 3) {
        ans += min((a[1] << 1) + a[n - 1] + a[n], a[1] + (a[2] << 1) + a[n]);
        n -= 2;
    }
    if (n == 2) ans += a[2];
    else if (n == 3) ans += a[1] + a[2] + a[3];
    printf("%d", ans);
    return 0;
}