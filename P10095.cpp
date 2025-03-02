#include <iostream>
using namespace std;
const int N = 1e2 + 5;
long long n, fib[N], ans;

void dfs(long long x, int idx) {
    if (x == 1) {
        ++ans;
        return;
    }
    if (idx == 2) {
        return;
    }
    while (x < fib[idx]) --idx;
    dfs(x, idx - 1);
    if (!(x % fib[idx]))
        dfs(x / fib[idx], idx);
}

int main() {
    int t;
    scanf("%d", &t);
    fib[1] = fib[2] = 1;
    for (int i = 3; i <= 87; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    cout << fib[87];
    while (t--) {
        ans = 0;
        scanf("%lld", &n);
        dfs(n, 87);
        printf("%d\n", ans);
    }
    return 0;
}