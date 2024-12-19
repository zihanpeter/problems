#include <iostream>
using namespace std;
const int N = 3e4 + 5, INF = 0x3f3f3f3f;
int n, d[N], sum1[N], sum2[N];


int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", d + i);
    for (int i = 1; i <= n; ++i) {
        if (d[i] == 2) sum2[i] = sum2[i - 1] + 1;
        else sum2[i] = sum2[i - 1];
    }
    for (int i = n; i >= 1; --i) {
        if (d[i] == 1) sum1[i] = sum1[i + 1] + 1;
        else sum1[i] = sum1[i + 1];
    }
    int ans = INF;
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, sum1[i + 1] + sum2[i - 1]);
    }
    printf("%d", ans);
    return 0;
}