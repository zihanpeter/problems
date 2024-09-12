#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, num2 = 0, num5 = 0;
    long long ans = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        ans *= i;
        while (ans % 5 == 0) {
            ++num5;
            ans /= 5;
        }
        while (ans % 2 == 0) {
            ++num2;
            ans /= 2;
        }
        num2 -= num5;
        num5 = 0;
        ans %= 10;
    }
    while (num2) {
        --num2;
        ans = ans * 2 % 10;
    }
    printf("%lld", ans);
    return 0;
}