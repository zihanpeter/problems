#include <iostream>
using namespace std;
int n, a[5], b[5], ans;
bool tong[105][105][105];

bool check(int x, int y) {
    if (x > y) swap(x, y);
    if (abs(x - y) <= 2 || abs(x + n - y) <= 2) return true;
    return false;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= 3; ++i) scanf("%d", a + i);
    for (int i = 1; i <= 3; ++i) scanf("%d", b + i);
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= n; ++j) 
            for (int k = 1; k <= n; ++k) {
                if (check(i, a[1]) && check(j, a[2]) && check(k, a[3]) && !tong[i][j][k]) {
                    tong[i][j][k] = true;
                    ++ans;
                }
                if (check(i, b[1]) && check(j, b[2]) && check(k, b[3]) && !tong[i][j][k]) {
                    tong[i][j][k] = true;
                    ++ans;
                }
            }
    printf("%d", ans);
    return 0;
}