#include <cstdio>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n, a[N], b[N];
priority_queue<int> q;
bool cmp(int x, int y) {
    return x > y;
}
signed main() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i) 
        scanf("%lld", a + i);
    for (int i = 1; i <= n; ++i) 
        scanf("%lld", b + i);
    sort(a + 1, a + n + 1, cmp);
    sort(b + 1, b + n + 1, cmp);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n / i; ++j) {
            q.push(a[i] * b[j]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%lld ", q.top());
        q.pop();
    }
    return 0;
}