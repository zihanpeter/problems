#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int N = 1e6 + 5;
int sa[N], x[N], y[N], tong[N], n;
string s;

void getSa() {
    int m = 127;
    memset(tong, 0, sizeof(tong));
    for (int i = 0; i < n; ++i) ++tong[x[i] = s[i]];
    for (int i = 1; i < m; ++i) tong[i] += tong[i - 1];
    for (int i = n - 1; ~i; --i) sa[--tong[x[i]]] = i;
    for (int k = 1; k <= n; k <<= 1) {
        int p = 0;
        for (int i = n - k; i < n; ++i) y[p++] = i;
        for (int i = 0; i < n; ++i) if (sa[i] >= k) y[p++] = sa[i] - k;
        memset(tong, 0, sizeof(tong));
        for (int i = 0; i < n; ++i) ++tong[x[y[i]]];
        for (int i = 1; i < m; ++i) tong[i] += tong[i - 1];
        for (int i = n - 1; ~i; --i) sa[--tong[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (int i = 1; i < n; ++i) x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1: p++;
        if (p >= n) break;
        m = p;
    }
}

int main() {
    getline(cin, s);
    n = s.length();
    getSa();
    for (int i = 0; i < n; ++i) printf("%d ", sa[i] + 1);
    return 0;
}