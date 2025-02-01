#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
int n;
struct node {
    int a, t, num;
} nds[N];
bool operator < (const node &x, const node &y) {
    return x.num > y.num;
}
priority_queue<node> q;
bool cmp(node x, node y) {
    if (x.a == y.a) return x.num < y.num;
    return x.a < y.a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> nds[i].a >> nds[i].t;
        nds[i].num = i;
    }
    sort(nds + 1, nds + n + 1, cmp);
    int fin = nds[1].a, ans = 0, li = 2;
    q.push(nds[1]);
    while (!q.empty()) {
        node x = q.top();
        q.pop();
        if (fin < x.a) fin = x.a;
        // cout << x.num << ' ' << x.a << ' ' << fin << ' ' << fin - x.a << endl;
        ans = max(ans, abs(fin - x.a));
        fin += x.t;
        while (li <= n && nds[li].a <= fin) {
            q.push(nds[li]);
            ++li;
        }
        if (q.empty() && li <= n) {
            q.push(nds[li]);
            ++li;
        }
    }
    cout << ans;
    return 0;
}