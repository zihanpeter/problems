// luogu P2292 90pts
#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int n, m, trie[N][30], cnt, ed[205], dp[N];
char s[N];

void insert() {
    int pos = 0;
    int n = strlen(s);
    for (int i = 0; i < n; ++i) {
        if (!trie[pos][s[i] - 'a']) trie[pos][s[i] - 'a'] = ++cnt;
        pos = trie[pos][s[i] - 'a'];
    }
    ed[pos] = 1;
}

int query() {
    int ans = 0;
    int n = strlen(s + 1);
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i <= n; ++i) {
        if (dp[i]) {
            int pos = 0, j = i + 1;
            while (trie[pos][s[j] - 'a'] && j <= n) {
                pos = trie[pos][s[j] - 'a'];
                if (ed[pos]) {
                    dp[j] = 1;
                    ans = max(ans, j);
                }
                ++j;
            }
        }
    }
    return ans;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s);
        insert();
    }
    while (m--) {
        scanf("%s", s + 1);
        printf("%d\n", query());
    }
    return 0;
}