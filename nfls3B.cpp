#include <iostream>
#include <cmath>
using namespace std;
const int INF = 0x3f3f3f3f;
int N, n;
int main() {
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &n);
        n *= 2;
        int ans = -INF;
        for (int i = 2; i * i<= n; ++i) {
            int xpy = n / i;
            if (n % i) continue;
            int fir = (n / 2 - i * (i - 1) / 2) / i;
            if ((n / 2 - i * (i - 1) / 2) % i) continue;
            if (fir * 2 + i - 1 == xpy) {
                ans = fir;
                break;
            }
        }
        if (ans == -INF) printf("IMPOSSIBLE\n");
        else {
            int sum = ans;
            printf("%d = %d", n / 2, ans);
            while (sum < n / 2) {
                ++ans;
                printf(" + %d", ans);
                sum += ans;
            }
            printf("\n");
        }
    }
    return 0;
}
