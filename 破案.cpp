#include <iostream>
#include <set>
using namespace std;
int n, m;
struct node {
    int x, y, z;
};
bool operator < (const node &x, const node &y) {
    if (x.x == y.x) {
        if (x.y == y.y) {
            return x.z < y.z;
        } else return x.y < y.y;
    } else return x.x < y.x;
}
set<node> s;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        node t;
        cin >> t.x >> t.y >> t.z; 
        s.insert(t);
    }
    for (int i = 1; i <= m; i++) {
        node t;
        cin >> t.x >> t.y >> t.z;
        if (s.count(t)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}