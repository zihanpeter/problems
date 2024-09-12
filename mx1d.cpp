#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
const int N = 35;
int n, m, f[N][N];
string s[N];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> s[i];
    f[1][1] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j - 1] == '#') continue;
            f[i][j] += f[i - 1][j] + f[i][j - 1];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << f[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}