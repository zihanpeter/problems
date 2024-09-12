#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
const int N = 5e4 + 5;
int n, d, ans;
struct node {
    int x, h;
} a[N];
deque<int> q;
bool tong[N];
bool cmp(node x, node y) {
    return x.x < y.x;
}
int main() {
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) 
        cin >> a[i].x >> a[i].h;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; ++i) {
        while (!q.empty() && a[q.back()].h < a[i].h)
            q.pop_back();
        while (!q.empty() && abs(a[i].x - a[q.front()].x) > d)
            q.pop_front();
        q.push_back(i);
        if (a[q.front()].h >= 2 * a[i].h) 
            tong[i] = true;
    }
    q.clear();
    for (int i = n; i >= 1; --i) {
        while (!q.empty() && a[q.back()].h < a[i].h) 
            q.pop_back();
        while (!q.empty() && abs(a[i].x - a[q.front()].x) > d)
            q.pop_front();
        q.push_back(i);
        if (a[q.front()].h >= 2 * a[i].h) 
            tong[i] = true;
    }
    for (int i = 1; i <= n; ++i) 
        if (tong[i]) ++ans;
    cout << ans << endl;
    return 0;
}