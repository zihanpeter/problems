#include <iostream>
#include <cmath>
using namespace std;
const int N = 1e3 + 5;
int n, nx[N], ny[N], f[N];

int find(int x) {
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}

bool check(int x) {
    for (int i = 1; i <= n; ++i) f[i] = i;

    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (pow(1ll * nx[i] - nx[j], 2) + pow(1ll * ny[i] - ny[j], 2) < x) {
                int fx = find(i), fy = find(j);
                if (fx != fy) {
                    f[fx] = fy;
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int fx = find(i), fy = find(j);
            if (fx != fy) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> nx[i] >> ny[i];
    }

    int l = 0, r = 1e9, ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            r = mid - 1;
            ans = r;
        } else l = mid + 1;
    }
    cout << ans;
    return 0;
}