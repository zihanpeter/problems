#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int t, m, vi[N], wi[N], f[1005];
int main() {
    cin >> t >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> wi[N] >> vi[N];
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = t; j >= 1; --j) {
            if (j >= wi[i]) {
                f[j] = max(f[j], vi[i] + f[j - wi[i]]);
            }
        }
    }
    cout << f[t];
    return 0;
}