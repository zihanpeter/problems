#include <iostream>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
	int n, a, minf = INF, maxf = -INF;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a);
		minf = min(minf, a);
		maxf = max(maxf, a);
	}
	printf("%d", maxf - minf);
	return 0;
}
