#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, k, a[N], first[N];
inline int read() {
    int x = 0, w = 0;
    char ch = 0;
    while (!isdigit(ch)) {
        w |= (ch == '-');
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return w ? -x : x;
}
int main() {
    n = read();
    k = read();
    int t;
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
        if (a[i] > k) a[i] = 1;
        else if (a[i] == k) {
            a[i] = 0;
            t = i;
        }else a[i] = -1;
    }
    for (int i = 1; i <= n; ++i) {
        first[i] = first[i - 1] + a[i];
    }
    int ans = 0;
    for (int i = t; i <= n; ++i) {
        for (int j = i; j >= 1; j -= 2) {
            if (first[i] - first[j - 1] == 0) 
                ++ans;
        }
    }
    printf("%d", ans);
    return 0;
}