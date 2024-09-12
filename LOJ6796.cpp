#include <iostream>
using namespace std;
const int N = 2e5 + 5, INF = 0x3f3f3f3f;
int n, a[N], b[N], c[N];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d%d", a + i, b + i, c + i);
    }
    int ans = -INF;
    int xyz = -INF;
    for (int i = 1; i <= n; ++i) {
    	xyz = max(xyz, - a[i] - b[i] - c[i]);
	}
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, a[i] + b[i] + c[i] + xyz);
    }
    int x = -INF, y = -INF, z = -INF;
    for (int i = 1; i <= n; ++i) {
        x = max(x, a[i]);
        y = max(y, b[i]);
        z = max(z, c[i]);
    }
    for (int i = 1; i <= n; ++i) {
        
    }
    return 0;
}
