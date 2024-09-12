#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
int n, logn, deep[N], father[N], jump[N][30], q;
ll dis[N];
struct node {
    int x, w;
};
vector<node> g[N];
void dfs(int x, int fa) {
    deep[x] = deep[fa] + 1;
    father[x] = fa;
    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i].x;
        if (y == fa) 
            continue;
        dis[y] = dis[x] + g[x][i].w;
        dfs(y, x);
    }
}
void initJump() {
    for (int i = 1; i <= n; ++i) 
        jump[i][0] = father[i];
		// for (int i = 1; i <= n; ++i) {
			// cout << jump[i][0] << ' ';
		// }
		// cout << endl;
    for (int j = 1; j <= logn; ++j) {
        for (int i = 1; i <= n; ++i) {
            jump[i][j] = jump[jump[i][j - 1]][j - 1];
			// cout << jump[i][j] << ' ';
			
		}
		// cout << endl;
	}
	
}
int lca(int x, int y) {
    if (deep[x] < deep[y]) 
        swap(x, y);

    int t = deep[x] - deep[y], k = 0;
	// cout<<t<<" ";
    while (t) {
        if (t & 1) 
            x = jump[x][k];
			
			// cout<<x<<endl;
        t >>= 1;
        ++k;
    }
    if (x == y) 
        return x;
    for (int i = logn; i >= 0; --i) {
        if (jump[x][i] == jump[y][i])
            continue;
        x = jump[x][i];
        y = jump[y][i];
    }
    return jump[x][0];
}
int main() {
    scanf("%d", &n);
    logn = log2(n);
    for (int i = 1; i < n; ++i) {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        g[u].push_back(node{v, d});
        g[v].push_back(node{u, d});
    }
	
    dfs(1, 0);
	initJump();
	// cout << " -------------" << endl;
	//for (int i = 1; i <= n; ++i) {
		// cout << father[i] << ' ' ;
	// }
	// cout << endl;
    scanf("%d", &q);
    ll lastans = 0;
    while (q--) {
        int a, b;
        scanf("%d%d", &a, &b);
        int x = (lastans + a) % n + 1;
        int y = (lastans + b) % n + 1;
		
        lastans = dis[x] + dis[y] - 2 * dis[lca(x, y)];
        printf("%lld\n", lastans);
    }
    return 0;
}
