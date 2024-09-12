#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, info[55][55], x, y;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &info[i][j]);
            y = max(y, info[i][j] * 3 + (x - 1) * 2 + 1);
        }
    x = 4 * m + 2 * n + 1;
    
    return 0;
}