#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e4 + 5;
int n, w, a[N], f[N];

int main() {
    scanf("%d%d", &n, &w);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    memset(f, 0x3f, sizeof(f));
    f[0] = 1;
    for (int i = 1; i <= w; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i >= a[j]) f[i] = min(f[i], f[i - a[j]] + 1);
        }
    }
    printf("%d", f[w] - 1);
    return 0;
}