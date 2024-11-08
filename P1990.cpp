#include <iostream>
using namespace std;
const int N = 1e6 + 5;
int n, f[N], x[N];

int main() {
    scanf("%d", &n);
    f[1] = f[0] = 1;
    x[1] = 1;
    for (int i = 2; i <= n; ++i) {
        f[i] = (f[i - 1] + f[i - 2] + (x[i - 2] << 1)) % 10000;
        x[i] = (f[i - 1] + x[i - 1]) % 10000;
    }
    printf("%d", f[n]);
    return 0;
}


