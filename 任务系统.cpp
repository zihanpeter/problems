#include <bits/stdc++.h>
using namespace std;
struct node {
    int data, time;
};
bool operator > (const node &x, const node &y){
    if(x.time == y.time) return x.data > y.time;
    return x.time > y.time;
}
priority_queue<node, vector<node>, greater<node> > q;
int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        string s;
        int x, y;
        cin >> s >> x >> y;
        q.push(node{x, y});
    }
    for (int i = 1; i <= k; i++) {
        cout << q.top().data << endl;
        node t = q.top();
        q.pop();
        t.time += k;
        q.push(t);
    }
    return 0;
}