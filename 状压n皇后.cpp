#include <iostream>
using namespace std;
int n, ans, side;
int lowbit(int x) {
    return x & (-x);
}
void dfs(int t, unsigned int row, unsigned int lrow, unsigned int rrow) {
    if (t == n + 1) {
        ++ans;
        return;
    }
    unsigned int pos = row | lrow | rrow;
    pos = ~pos;
    // cout << pos << endl;
    while (pos > 0) {
        int k = lowbit(pos);
        pos -= k;
        if (k <= side) {
            dfs(t + 1, row + k, (lrow + k) >> 1, (rrow + k) << 1);
        }
    }
}
int main() {
    cin >> n;
    side = (1 << n) - 1;
    dfs(1, 0, 0, 0);
    cout << ans << endl;
    return 0;
}