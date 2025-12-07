#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n, a[N], b[N];
vector<int> pos[N];

int lowbit(int x) {
    return x & -x;
}

void add(int k, int x) {
    while (k <= n) {
        b[k] += x;
        k += lowbit(k);
    }
}

int find(int k) {
    int ans = 0;
    while (k >= 1) {
        ans += b[k];
        k -= lowbit(k);
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }

    for (int i = 1; i <= n; ++i) {
        add(i, 1);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cout << ans << endl;
        for (int j = 0; j < pos[i].size(); ++j) {
            add(pos[i][j], -1);
        }
        for (int j = 0; j < pos[i].size(); ++j) {
            ans += find(pos[i][j]);
        }
    }
    return 0;
}