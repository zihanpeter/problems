#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, L, a[N], f[N], pre[N];

int main() {
    cin >> n >> L;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + a[i];
    f[n] = 1;
    int sum = a[n];
    for (int i = n - 1, j = n; i >= 1; --i) {
    	sum += a[i];
    	if (sum <= L) {
    		f[i] = f[i + 1];
    		continue;
    	}
    	while (sum > L) {
    		sum -= a[j];
    		--j;
		}
		f[i] = f[j + 1] + 1;
	}
	for (int i = 1; i <= n; ++i) cout << f[i] << ' ';
    return 0;
}
