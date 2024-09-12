#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5 + 5;

int n, a[N], b[N];

int check(int mid) {
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (mid + abs(n / 2 + 1 - i) ^ a[i]) cnt += abs(mid + abs(n / 2 + 1 - i) - a[i]);
        if (mid + abs(n / 2 + 1 - i) ^ b[i]) cnt += abs(mid + abs(n / 2 + 1 - i) - b[i]);
    }
    return cnt;
}

main() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
    for (int i = 1; i <= n; ++i) scanf("%lld", b + i);
    int l = 0, r = 1e12, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid) < check(mid + 1)) {
            r = mid - 1;
            ans = mid;
        } else l = mid + 1;
    }
    printf("%lld", check(ans));
    return 0;
}