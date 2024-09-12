#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 1e3 + 5;
int n, a[N], ans = 0x3f3f3f3f;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) 
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 0; i <= 100; ++i) {
        int l = i, r = i + 17;
        if (r >= 100) 
            continue;
        int sum = 0;
        for (int j = 1; j <= n; ++j) {
            if (a[j] >= l && a[j] <= r) 
                continue;
            sum += min(abs(a[j] - l) * abs(a[j] - l), abs(a[j] - r) * abs(a[j] - r));
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}