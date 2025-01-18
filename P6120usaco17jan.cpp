// P6120 [USACO17JAN] Hoof, Paper, Scissor S
#include <iostream>
using namespace std;
const int N = 1e5 + 5;
int n, h[N], p[N], s[N];
char str[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> str[i];
    for (int i = 1; i <= n; ++i) {
        h[i] = h[i - 1], p[i] = p[i - 1], s[i] = s[i - 1];
        if (str[i] == 'H') ++p[i];
        if (str[i] == 'P') ++s[i];
        if (str[i] == 'S') ++h[i];
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans = max(ans, p[i] + s[n] - s[i]);
        ans = max(ans, p[i] + h[n] - h[i]);
        ans = max(ans, s[i] + p[n] - p[i]);
        ans = max(ans, s[i] + h[n] - h[i]);
        ans = max(ans, h[i] + p[n] - p[i]);
        ans = max(ans, h[i] + s[n] - s[i]);
    }
    cout << ans;
    return 0;
}