#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
struct node {
    char s[N];
    int res;
} nds[N];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m, res;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; ++i) {
            scanf("%s%d", nds[i].s + 1, &nds[i].res);
            
        }
    }
    return 0;
}