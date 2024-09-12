#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int N = 1e3 + 5;
const int mod = 998244353;
int info[N][N], right0[N][N], under0[N][N], sum[N][N];
int main() {
    int T, id;
    cin >> T >> id;
    while (T--) {
        memset(right0, 0, sizeof(right0));
        memset(under0, 0, sizeof(under0));
        memset(sum, 0, sizeof(sum));
        int n, m, c, f;
        string s;
        cin >> n >> m >> c >> f;
        for (int i = 1; i <= n; ++i) {
            cin >> s;
            for (int j = 1; j <= m; ++j) 
                info[i][j] = s[j - 1] - '0';
        }
        for (int i = 1; i <= n; ++i) {
            int t = 0;
            for (int j = m; j >= 1; --j) {
                if (info[i][j] == 1) {
                    t = 0;
                    right0[i][j] = 0;
                } else {
                    ++t;
                    right0[i][j] = t - 1;
                }
            }
        }
        for (int j = 1; j <= m; ++j) {
            int t = 0;
            for (int i = n; i >= 1; --i) {
                if (info[i][j] == 1) {
                    t = 0;
                    under0[i][j] = 0;
                } else {
                    ++t;
                    under0[i][j] = t - 1;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (info[i][j] == 1) {
                    sum[i][j] = 0;
                } else {
                    sum[i][j] = sum[i - 1][j] + right0[i][j];
                }
            }
        }
        // for (int i = 1; i <= n; ++i) {
        //     for (int j = 1; j <= m; ++j) {
        //         cout << right0[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        // cout << "-----------------------------" << endl;
        // for (int i = 1; i <= n; ++i) {
        //     for (int j = 1; j <= m; ++j) {
        //         cout << under0[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        // cout << "-----------------------------" << endl;
        // for (int i = 1; i <= n; ++i) {
        //     for (int j = 1; j <= m; ++j) {
        //         cout << sum[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        int Vc = 0, Vf = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (under0[i][j] < 2) 
                    continue;
                Vc = ((Vc % mod) + ((sum[i + under0[i][j]][j] - sum[i][j]) % mod) * ((right0[i][j]) % mod)) % mod;
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (under0[i][j] < 3) 
                    continue;
                Vf = ((Vf % mod) + ((sum[i + under0[i][j] - 1][j] - sum[i][j]) % mod) * ((right0[i][j]) % mod)) % mod;
            }
        }
        cout << c * Vc % mod << ' ' << f * Vf % mod << endl;
    }
    return 0;
}