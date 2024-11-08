#include <iostream>
#include <algorithm>
using namespace std;
int n;
struct node {
    string s;
    int y, m, d, num;
} nds[105];
bool cmp(node x, node y) {
    if (x.y == y.y) {
        if (x.m == y.m) {
            if (x.d == y.d) return x.num > y.num;
            return x.d < y.d;
        }
        return x.m < y.m;
    }
    return x.y < y.y;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> nds[i].s >> nds[i].y >> nds[i].m >> nds[i].d;
        nds[i].num = i;
    }
    sort(nds + 1, nds + n + 1, cmp);
    for (int i = 1; i <= n; ++i) cout << nds[i].s << '\n';
    return 0;
}