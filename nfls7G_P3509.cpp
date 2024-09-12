//洛谷上提交需要定义为 int jump[N][65]; 

#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
int n, k, jump[65][N], ans[N];
ll m, dis[N]; 
int main() {
	scanf("%d%d%lld", &n, &k, &m);
	for (int i = 1; i <= n; ++i) scanf("%lld", dis + i);
	// 处理距离每个点的第k大的点
	int l = 1, r = k + 1;
	for (int i = 1; i <= n; ++i) {
		while (r + 1 <= n && dis[i] - dis[l] > dis[r + 1] - dis[i]) ++l, ++r;
		if (dis[r] - dis[i] > dis[i] - dis[l]) jump[0][i] = r;
		else jump[0][i] = l;
	}
	for (int i = 1; i <= 60; ++i) 
		for (int j = 1; j <= n; ++j) 
			jump[i][j] = jump[i - 1][jump[i - 1][j]];
	for (int i = 1; i <= n; ++i) ans[i] = i;
	int t = 0;
	while (m) {
		if (m & 1) for (int i = 1; i <= n; ++i) ans[i] = jump[t][ans[i]];
		m >>= 1;
		++t;
	}
	for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
	return 0;
}
