#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
const int N = 2e5 + 5, INF = 0x3f3f3f3f;
int n, a[N], b[N], cnt;
bool flag;
struct node {
    int x, pos;
} sorted[N], stkSeq[N];
stack<node> stk;

bool cmp(node x, node y) {
    if (x.x == y.x) return x.pos < y.pos;
    return x.x > y.x;
}

// void dfs(int l, int r, int maxi) {
//     // cout << "flag" << flag << endl;
//     // for (int i = l; i <= r; ++i) {
//     //     cout << a[i] << ' ';
//     // }
//     // cout << endl;
//     if (l > r) {
//         return;
//     }
//     int maxf = -INF, maxl = 0;
//     for (int i = l; i < maxi; ++i) {
//         if (a[i] > maxf) {
//             maxf = a[i];
//             maxl = i;
//         }
//     }
//     maxf = -INF; int maxr = 0;
//     for (int i = maxi + 1; i <= r; ++i) {
//         if (a[i] > maxf) {
//             maxf = a[i];
//             maxr = i;
//         }
//     }
//     b[++cnt] = a[maxi];
//     if (a[maxl] > a[maxr] && flag) {
//         for (int i = maxi; i <= r; ++i) {
//             a[i] = a[i + 1];
//         }
//         if (maxi ^ l) flag = false;
//         dfs(l, r - 1, maxl);
//     }
//     else {
//         dfs(maxi + 1, r, maxr);
//     }
// }

void buildStack() {
    for (int i = 1; i <= n; ++i) {
        while (!stk.empty() && stk.top().x < a[i]) stk.pop();
        stk.push(node{a[i], i});
    }
    while (!stk.empty()) {
        stkSeq[++cnt] = stk.top();
        stk.pop();
    }
    reverse(stkSeq + 1, stkSeq + cnt + 1);
}

int main() {
    freopen("usaco2025febAs.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        // cout << "-------" << endl;
        cin >> n;
        flag = true;
        cnt = 0;
        int maxf = 0, maxi = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            sorted[i].x = a[i];
            sorted[i].pos = i;
        }
        buildStack();
        // dfs(1, n, maxi);
        for (int i = 1; i <= cnt; ++i) {
            cout << b[i];
            if (i != cnt) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}