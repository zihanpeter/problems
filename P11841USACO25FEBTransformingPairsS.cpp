#include <iostream>
using namespace std;
long long a, b, c, d, ans;

void dfs(long long x, long long y, long long sum) {
    if (x < a || y < b) return;
    if (x == a && y == b) {
        ans = sum;
        return;
    }
    if (x > y) {
        if (y == b && (x - a) % y == 0) dfs(a, y, sum + (x - a) / y);
        else dfs(x % y, y, sum + x / y);
    } else {
        if (x == a && (y - b) % x == 0) dfs(x, b, sum + (y - b) / x);
        else dfs(x, y % x, sum + y / x);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        ans = -1;
        cin >> a >> b >> c >> d;
        dfs(c, d, 0);
        cout << ans << '\n';
    }
    return 0;
}