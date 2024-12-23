#include <iostream>
using namespace std;
const int N = 1e4 + 5, INF = 0x3f3f3f3f;
int n, a[N], f[N], s[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    f[1] = 1;
    s[1] = a[1];
    for (int i = 2; i <= n; ++i) {
        for (int j = i; j >= 1; --j) {
            if (a[j] <= a[i] && f[j] + 1 >= f[i]) {
                f[i] = f[j] + 1;
                s[i] = s[j] + a[i];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", s[i]);
    }
    return 0;
}