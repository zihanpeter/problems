#include <iostream>
#include <vector>
using namespace std;
const int N = 2e4 + 5;
int n;
vector<int> g[N];
void dfs(int x, int fa) {
    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i];
        if (y == fa) {
            continue;
        }
    }
}
int main() {
	cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    return 0;
}