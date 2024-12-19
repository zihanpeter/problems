#include <iostream>
using namespace std;
const int N = 1e6 + 5;
int n, h[N], f[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", h + i);
	f[1] = f[0] + h[1];
	f[2] = min(f[1] + h[2], f[0] + h[2]);
	for (int i = 3; i <= n + 1; ++i) {
		f[i] = min(f[i - 1] + h[i], min(f[i - 2] + h[i], f[i - 3] + h[i]));
	}
	printf("%d", f[n + 1]);
	return 0;
}
