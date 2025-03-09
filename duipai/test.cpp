#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
const int N = 2e5 + 5, INF = 0x3f3f3f3f;
int n, a[N], b[N], stkSeq[N], cnt;
stack<int> stk;

int main() {
    freopen("sample.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        int maxi = n;
        for (int i = n; i >= 1; --i) {
            if (a[i] >= a[maxi]) maxi = i;
            b[i] = maxi;
        }
        for (int i = 1; i <= n; ++i) 
            if (b[i] > i) {
                int temp = a[b[i]];
                for (int j = b[i]; j >= i; --j) a[j] = a[j - 1];
                a[i] = temp;
                break;
            }
        cnt = 0;
        for (int i = 1; i <= n; ++i) {
            while (!stk.empty() && stk.top() < a[i]) stk.pop();
            stk.push(a[i]);
        }
        while (!stk.empty()) {
            stkSeq[++cnt] = stk.top();
            stk.pop();
        }
        reverse(stkSeq + 1, stkSeq + cnt + 1);
        for (int i = 1; i <= cnt; ++i) cout << stkSeq[i] << ' ';
        cout << '\n';
    }
    return 0;
}