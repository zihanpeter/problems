#include <iostream>
#define int long long
using namespace std;
const int M = 1e9 + 7;
int k, n, l, km2;
string s;

int quick_pow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = res * x % M;
        y >>= 1;
        x = x * x % M;
    }
    return res;
}

int kx(int x, int y) {
    int res = 1;
    for (int i = x; i >= x - y + 1; --i) res = res * i % M;
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k >> n >> l;
    cin >> s;

    km2 = quick_pow(kx(k, k), M - 2);

    int cnt_o = 0, ans = 1;
    for (int i = s.length() - 1; i; --i) {
        if (s[i] == 'O') ++cnt_o;
        if (s[i] == 'M' && cnt_o >= k) {
            ans = ans * kx(cnt_o, k) % M * km2 % M;
            cnt_o -= k;
        }
    }
    cout << quick_pow(ans, l);
    return 0;
}