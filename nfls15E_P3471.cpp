#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int BASE = 127;
unordered_map<ull, int> dic;
int n, m, q;
ull ht[1005], power[105];
ull hasher(string s) {
    ull res = 0;
    for (int i = 0; i < s.length(); ++i) res = res * BASE + s[i];
    return res;
}
string ss[1005];
int main() {
    power[0] = 1;
    for (int i = 1; i <= 100; ++i) power[i] = power[i - 1] * BASE;
    scanf("%d%d%d", &n, &m, &q);
    getchar();
    for (int i = 1; i <= n; ++i) getline(cin, ss[i]), ht[i] = hasher(ss[i]), ++dic[ht[i]];
    int x, y, z, t;
    while (q--) {
        scanf("%d%d%d%d", &x, &y, &z, &t);
        --y, --t;
        char a = ss[x][y], b = ss[z][t];
        ull h1 = ht[x] - a * power[y], h2 = ht[z] - b * power[t];
        --dic[ht[x]], --dic[ht[z]];
        h1 = ht[x] + b * power[y], h2 = ht[z] + a * power[t];
        printf("%d\n", )
    }
    return 0;
}