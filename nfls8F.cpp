#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 2005;
struct node {
    int x, pos;
};
bool operator > (const node &x, const node &y) {
    if (x.x == y.x) return x.pos > y.pos;
    return x.x > y.x;
}
priority_queue<node, vector<node>, greater<node> > pq;
struct nd2 {
    int x[N];
} q[N];
int poser[N];
int n;
bool cmp(nd2 x, nd2 y) {
    for (int i = 1; i <= min(x.x[0], y.x[0]); ++i) 
        if (x.x[i] < y.x[i]) return true;
        else if (x.x[i] > y.x[i]) return false;
    return x.x[0] < y.x[0];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x, y;
        scanf("%d", &x);
        q[i].x[0] = x;
        for (int j = 1; j <= x; ++j) {
            scanf("%d", &y);
            q[i].x[j] = y;
        }
        q[i].x[x + 1] = 0x3f3f3f3f;
    }
    sort(q + 1, q + n + 1, cmp);
    for (int i = 1; i <= n; ++i) {
        ++poser[i];
        pq.push(node{q[i].x[poser[i]], i}); 
    }
    while (!pq.empty()) {
        node t = pq.top();
        pq.pop();
        printf("%d ", t.x);
        if (poser[t.pos] < q[t.pos].x[0]) {
            ++poser[t.pos];
            pq.push(node{q[t.pos].x[poser[t.pos]], t.pos});
        }
    }
    return 0;
}