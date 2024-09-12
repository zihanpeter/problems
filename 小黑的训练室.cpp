#include <iostream>
using namespace std;
const int N = 3e2 + 5;

int n, m, t, g[N][N];
int main () {
    cin >> n >> m >> t;
    int x, y, z;
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y >> z;
        g[x][y] = z;
    }
    for (int k = 1; k <= n; ++k) 
        for (int i = 1; i <= n; ++i) 
            for (int j = 1; j <= n; ++j) 
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    for (int i = 1; i <= t; ++i) {
        cin >> x >> y;
        cout << g[x][y] << endl;
    }
    return 0;
}