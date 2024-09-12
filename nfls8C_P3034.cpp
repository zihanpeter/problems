#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int N = 2e4 + 5;
int n, ans[N];
unordered_map<int, int> pos[10];
bool cmp(int x, int y) {
    int cnt = 0;
    for (int i = 1; i <= 5; ++i) if (pos[i][x] < pos[i][y]) ++cnt;
    return cnt >= 3;
}
int main() {
    scanf("%d", &n);
    int t;
    for (int i = 1; i <= 5; ++i) for (int j = 1; j <= n; ++j) {
        scanf("%d", &t);
        pos[i][t] = j;
        ans[j] = t;
    }
    sort(ans + 1, ans + n + 1, cmp);
    for (int i = 1; i <= n; ++i) printf("%d\n", ans[i]);
    return 0;
}