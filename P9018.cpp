#include <iostream>
#define int long long
using namespace std;
const int N = 1e6 + 5, P = 1e9 + 7;
int n, a[N], jie[N];

int quick_pow(int x, int y) {
    int ans = 1, k = x;
    while (y) {
        if (y & 1) ans = ans * k % P;
        k = k * k % P;
        y >>= 1;
    }
    return ans;
}

int C(int x, int y) {
    return jie[y] * quick_pow(jie[x] * jie[y - x] % P, P - 2) % P;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    jie[0] = 1;
    jie[1] = 1;
    for (int i = 2; i <= 1e6; ++i) jie[i] = jie[i - 1] * i % P;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] >>= 1;
    }

    int ans = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i + 1]) {
            ans = ans * C(a[i + 1], a[i]) % P;
        } else {
            ans = ans * C(a[i] - 1, a[i + 1] - 1) % P;
        }
    }
    cout << ans;
    return 0;
}