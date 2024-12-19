#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
const int N = 1e6 + 5;
int n, a[N], b[N], mk1[N], mk2[N];


int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(mk1, 0, sizeof(mk1));
        memset(mk2, 0, sizeof(mk2));
        stack<int> s1, s2;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", a + i);
        for (int i = 1; i <= n; ++i) scanf("%d", b + i);
        for (int i = 1; i <= n; ++i) {
            if (!s1.empty() && s1.top() == a[i]) {
                ++mk1[s1.top()];
                s1.pop();
            } else s1.push(a[i]);
        }
        for (int i = 1; i <= n; ++i) {
            if (!s2.empty() && s2.top() == b[i]) {
                ++mk2[s2.top()];
                s2.pop();
            } else s2.push(b[i]);
        }
        bool ans = true;
        for (int i = 1; i <= n; ++i) {
            if (mk1[i] != mk2[i]) {
                ans = false;
                break;
            }
        }
        while (!s1.empty() && !s2.empty()) {
            if (s1.top() != s2.top()) {
                ans = false;
                break;
            }
            s1.pop(); s2.pop();
        }
        if (!ans) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}