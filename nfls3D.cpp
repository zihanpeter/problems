#include <iostream>
#include <cstring>
using namespace std;
bool notPrime[205];
int n, cnt, prime[205], dp[205];
void init() {
    for (int i = 2; i <= 200; ++i) 
        if (!notPrime[i]) {
            prime[++cnt] = i;
            for (int j = 2; i * j <= 200; ++j) notPrime[i * j] = true;
        }
}
int main() {
    init();
    scanf("%d", &n);
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= cnt; ++i) 
        for (int j = n; j >= prime[i]; --j) 
            dp[j] = max(dp[j], dp[j - prime[i]] + 1);
    printf("%d", dp[n]);
    return 0;
}