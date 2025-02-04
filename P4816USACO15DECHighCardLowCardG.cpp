#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
int n, a[N], tong[N], b[N];
bool cmp(int x, int y) { return x > y; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        tong[a[i]] = true;
    }
    int t = 1, ans = 0;
    for (int i = 1; i <= n << 1; ++i) 
        if (!tong[i]) b[t++] = i;
    int l = (n >> 1) + 1, r = n;
    sort(a + 1, a + (n >> 1) + 1, cmp);
    for (int i = 1; i <= n >> 1; ++i) {
        if (b[r] > a[i]) {
            r--;
            ++ans;
        } else l++;
    }
    l = 1, r = (n >> 1);
    sort(a + (n >> 1) + 1, a + n + 1);
    for (int i = (n >> 1) + 1; i <= n; ++i) {
        if (b[l] < a[i]) {
            ++l;
            ++ans;
        } else --r;
    }
    cout << ans;
    return 0;
}