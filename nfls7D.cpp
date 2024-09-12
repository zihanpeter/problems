#include <iostream>
#include <deque>
using namespace std;
const int N = 2e5 + 5, INF = 0x3f3f3f3f;
deque<int> dq;
int n, k, a[N], sum[N], ans = -INF, l, r;
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = n + 1; i <= n * 2; ++i) a[i] = a[i - n];
    for (int i = 1; i <= n * 2; ++i) sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= n * 2; ++i) {
        while (!dq.empty() && sum[dq.back()] >= sum[i - 1]) dq.pop_back();
        dq.push_back(i - 1);
        while (dq.front() < i - k) dq.pop_front();
        if (sum[i] - sum[dq.front()] > ans) {
            ans = sum[i] - sum[dq.front()];
            l = dq.front() + 1;
            r = i;
        }
    }
    if (l > n) l -= n;
    if (r > n) r -= n;
    printf("%d %d %d", ans, l, r);
    return 0;
}