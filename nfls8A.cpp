#include <iostream>
using namespace std;
const int N = 1e4 + 5;

int n, a[N], sum, ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = 1; i <= n; ++i) sum += a[i];
    sum /= n;
    for (int i = 1; i <= n; ++i) if (sum > a[i]) ans += sum - a[i];
    printf("%d", ans);
    return 0;
}