#include <iostream>
using namespace std;
const int MOD = 998244353;

int quickPow(int x, int y) {
    int ans = 1, p = x;
    while (y) {
        if (y & 1) ans = 1ll * ans * p % MOD;
        p = 1ll * p * p % MOD;
        y >>= 1;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << 1ll * n * (n - 1) % MOD * (n - 2) % MOD * quickPow(6, MOD - 2) % MOD * quickPow(4, MOD - 2) % MOD;
    return 0;
}