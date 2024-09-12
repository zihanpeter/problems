#include <bits/stdc++.h>
using namespace std;
int a, b, c, dt, sqdt;
int main() {
    int T, M;
    cin >> T >> M;
    while (T--) {
        cin >> a >> b >> c;
        dt = b * b - 4 * a * c;
        if (dt < 0) {
            cout << "NO\n";
            continue;
        }
        sqdt = sqrt(dt);
        if (sqdt * sqdt == dt && (-b - sqdt) % (2 * a) == 0) {
            cout << max((-b - sqdt) / (2 * a), (-b + sqdt) / (2 * a)) << "\n";
        }
    }
    return 0;
}