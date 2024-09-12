#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e4 + 5;
int n, m, rudu[N];
vector<int> g[N];
priority_queue<int, vector<int>, greater<int> > q;
void tuoPo() {
    for (int i = 1; i <= n; ++i) 
        if (rudu[i] == 0) q.push(i);
    while (!q.empty()) {
        int x = q.top();
        cout << x << ' ';
        q.pop();
        for (int i = 0; i < g[x].size(); ++i) {
            int y = g[x][i];
            --rudu[y];
            if (rudu[y] == 0) {
                q.push(y);
            }
        }
    }
    return;
}
int main() {
    cin >> n >> m;
    int x, y;
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        g[x].push_back(y);
        ++rudu[y];
    }
    tuoPo();
    return 0;
}