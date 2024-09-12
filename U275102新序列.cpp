#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
using namespace std;
const int N = 1e6 + 5;
int n, a[N], v[N][10], primes[N], pos[N], d[N];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        pos[a[i]] = i;
    }
    for (int i = 2; i <= 1e6; ++i) 
    	if (!primes[i]) 
    		for (int j = 1; i * j <= 1e6; ++j) {
    			primes[i * j] = 1;
    			v[i * j][++v[i * j][0]] = i;
    		}
	int ans = -0x3f3f3f3f;
    for (int i = 1; i <= n; ++i) {
    	int maxd = -0x3f3f3f3f;
        for (int j = 1; j <= v[a[i]][0]; ++j) {
            int y = v[a[i]][j];
            maxd = max(maxd, d[y]);
        }
        ++maxd;
        ans = max(ans, maxd);
        for (int j = 1; j <= v[a[i]][0]; ++j) {
        	int y = v[a[i]][j];
        	d[y] = maxd; 
		}
    }
	printf("%d", ans);
    return 0;
}

