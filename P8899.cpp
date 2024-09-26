#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
bool rm[N];
struct node {
    string s;
    int res;
} nds[N];
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        memset(rm, 0, sizeof(rm));
        for (int i = 1; i <= m; ++i) cin >> nds[i].s >> nds[i].res;
        for (int k = 1; k <= n; ++k)
        for (int i = 0; i < n; ++i) {
            int ans1 = -1, ans0 = -1;
            bool flag1 = true, flag0 = true;
            for (int j = 1; j <= m; ++j) {
                if (rm[j]) continue;
                if (nds[j].s[i] == '1' && flag1) {
                    if (~ans1 && ans1 ^ nds[j].res) flag1 = false;
                    else ans1 = nds[j].res;
                } else if (nds[j].s[i] == '0' && flag0) {
                    if (~ans0 && ans0 ^ nds[j].res) flag0 = false;
                    else ans0 = nds[j].res;
                }
            }
            for (int j = 1; j <= m; ++j) 
                if (nds[j].s[i] == '1' && flag1) rm[j] = true;
                else if (nds[j].s[i] == '0' && flag0) rm[j] = true;
        }
        bool ans = true;
        for (int i = 1; i <= m; ++i) if (!rm[i]) ans = false;
        if (ans) cout << "OK\n";
        else cout << "LIE\n";
    }
    return 0;
}