#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5, INF = 0x3f3f3f3f;
int n, m;
int a[N], b[N], f[N], tong[N];

int main() {
    memset(f, 0x3f, sizeof(f));
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
	    scanf("%d", a + i);
        tong[a[i]] = i;
    }
	for (int i = 1; i <= n; ++i) {
	    scanf("%d", b + i);
        b[i] = tong[b[i]];
    }
    f[1] = b[1];
	for (int i = 2; i <= n; ++i) {
		int pos = 
	}
	printf("%d", f[n]);
	return 0;
}