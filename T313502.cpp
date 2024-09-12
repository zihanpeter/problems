#include <iostream>
#include <cmath>
#define int long long
using namespace std;
const int N = 2e3 + 5, MOD = 1e9 + 7;
int n, m, x, cntx[N], cnty[N], sumx[N], sumy[N], ans;
string s[N];

int quickPow(int a, int b) {
    int ans = 1, k = a;
    while (b) {
        if (b & 1) ans = 1ll * ans * k % MOD;
        k = 1ll * k * k % MOD;
        b >>= 1;
    }
    return ans;
}

signed main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) 
            if (s[i][j] == '1') {
                ++cntx[i]; ++cnty[j]; ++x;
            }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sumx[i] = (sumx[i] + 1ll * abs(j - i) * cntx[j] % MOD) % MOD;
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            sumy[i] = (sumy[i] + 1ll * abs(j - i) * cnty[j] % MOD) % MOD;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans ^= (sumx[i] + sumy[j]) % MOD * quickPow(x, MOD - 2) % MOD;
        }
    }
    cout << ans;
    return 0;
}