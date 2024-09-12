#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 1e2 + 5;
int n, tree[N], points[N][2];
double ans;
struct node {
    int x, y, w;
} side[N * N];
bool cmp(node x, node y) {
    return x.w < y.w;
}
int find(int x) {
    if (x == tree[x]) return x;
    return tree[x] = find(tree[x]);
}
void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy) tree[x] = y;
}
void init() {
    for (int i = 1; i <= n; i++) 
        tree[i] = i;
}
int main() {
    cin >> n; 
    for (int i = 1; i <= n; ++i) 
        cin >> points[i][0] >> points[i][1];
    int k = 0;
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= n; j++) {
            side[++k] = node{i, j, (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1])}; 
        }
    sort(side + 1, side + k + 1, cmp);
    init();
    int cnt = 0;
    for (int i = 1; i <= k; i++) {
        int x = side[i].x;
        int y = side[i].y;
        int w = side[i].w;
        if (find(x) == find(y)) continue;
        ans += sqrt(w);
        cout << sqrt(w) << endl;
        merge(x, y);
        cnt++;
        if (cnt > n - 1) break;
    }
    printf("%.2llf", ans);
    return 0;
}