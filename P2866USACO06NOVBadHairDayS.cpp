#include <bits/stdc++.h>
using namespace std;
const int N = 8e4 + 5;
int n, h[N], r[N];
stack<int> s;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) 
        scanf("%d", h + i);
    for (int i = 1; i <= n; ++i) {
        while (!s.empty() && h[s.top()] <= h[i]) {
            r[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        // cout << r[i] << ' ';
        if (r[i] == 0)
            r[i] = n + 1;
        ans += r[i] - i - 1;
    }
    printf("%lld", ans);
    return 0;
}