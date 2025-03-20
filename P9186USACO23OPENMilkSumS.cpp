#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
const int N = 2e5;
int n, a[N], q, b[N], pre[N], sum;

main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + b[i];
        sum += b[i] * i;
    }

    // for (int i = 1; i <= n; ++i) cout << b[i] << ' ';
    // cout << endl;
    
    int x, y, pos1, pos2;
    cin >> q;
    while (q--) {
        cin >> x >> y;
        pos1 = lower_bound(b + 1, b + n + 1, a[x]) - b;
        pos2 = upper_bound(b + 1, b + n + 1, y) - b;

        // cout << pos1 << ' ' << pos2 << endl;

        if (pos1 >= pos2) 
            cout << sum + (pre[pos1 - 1] - pre[pos2 - 1]) - b[pos1] * pos1 + y * pos2 << '\n';
        else 
            cout << sum - (pre[pos2 - 1] - pre[pos1]) - b[pos1] * pos1 + y * (pos2 - 1) << '\n';
    }
    return 0;
}