#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int m, s, c, a[N], b[N];
bool cmp(int x, int y) {
    return x > y;
}
int main() {
    cin >> m >> s >> c;
    for (int i = 1; i <= c; ++i) {
        cin >> a[i];
    }
    if (m > c) {
        cout << c;
        return 0;
    }
    sort(a + 1, a + c + 1);
    for (int i = 2; i <= c; ++i) {
        b[i - 1] = a[i] - a[i - 1];
    }
    sort(b + 1, b + c, cmp);
    int ans = a[c] - a[1] + 1;
    for (int i = 1; i <= m - 1; ++i) {
        ans -= b[i] - 1;
    }
    cout << ans;
    return 0;
}