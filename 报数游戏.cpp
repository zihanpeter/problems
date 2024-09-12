#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
typedef long long ll;
ll a[N];
int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", a + i);
        if (a[i] == 0) ++cnt;
    }
    sort(a + 1, a + n + 1);
    ll *pos = unique(a + 1, a + n + 1);
    if (cnt == 1) {
        printf("%d", pos - a - 2);
    } else {
        printf("%d", pos - a - 1);
    }
    return 0;
}