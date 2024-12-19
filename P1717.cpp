#include <iostream>
#include <queue>
using namespace std;
const int N = 25;
int n, h, f[N], d[N], t[N], pre[N];
priority_queue<int> q;

int main() {
    scanf("%d%d", &n, &h);
    for (int i = 1; i <= n; ++i) scanf("%d", f + i);
    for (int i = 1; i <= n; ++i) scanf("%d", d + i);
    for (int i = 1; i < n; ++i) {
        scanf("%d", t + i);
        pre[i] = pre[i - 1] + t[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        
    }
    return 0;
}