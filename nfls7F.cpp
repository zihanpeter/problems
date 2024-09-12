#include <iostream>
#include <cmath>
using namespace std;
const int N = 2e5 + 5;
int m, d, cnt, st[N][30];
int main() {
    scanf("%d%d", &m, &d);
    char c;
    int x, t = 0;
    while (m--) {
        getchar();
        scanf("%c %d", &c, &x);
        if (c == 'A') {
            st[++cnt][0] = (x + t) % d;
            for (int j = 1; 1 << j <= cnt; ++j) 
                st[cnt - (1 << j) + 1][j] = max(st[cnt - (1 << j) + 1][j - 1], st[cnt - (1 << j - 1) + 1][j - 1]);  
        } else {
            int logn = log2(x);
            t = max(st[cnt - x + 1][logn], st[cnt - (1 << logn) + 1][logn]);
            printf("%d\n", t);
        }
    }
    return 0;
}