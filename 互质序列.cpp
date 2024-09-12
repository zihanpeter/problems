/*
枚举一个状态的子集
for (int i = s; i; i = (i - 1) & s)
*/
#include <iostream>
using namespace std;
typedef long long ll;
int prime[20] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
int dp[105][32773];
ll a, b;
int cnt, primec[20], n, sta[105];
int main() {
	scanf("%lld%lld", &a, &b);
	n = b - a + 1;
	for (ll i = a; i <= b; ++i) 
		for (int j = 1; j <= 15; ++j) 
			if (i % prime[j] == 0) {
				primec[++cnt] = prime[j];
			}
	for (int j = 0; j < (1 << cnt); ++j) {
		dp
	}		
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < (1 << cnt); ++j) {
			
		}
	}
    return 0;
}
