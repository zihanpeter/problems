#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
ll n, a[N], first[N], fleft[N], fright[N];
void minRight() {
    stack<ll> s;
    for (int i = 1; i <= n; i++) {
        while (!s.empty() && a[s.top()] > a[i]) {
            fright[s.top()] = i - 1;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty()) {
        fright[s.top()] = n;
        s.pop();
    }
    return;
}
void minLeft() {
    stack<ll> s;
    for (int i = n; i >= 1; i--) {
        while (!s.empty() && a[s.top()] > a[i]) {
            fleft[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty()) {
        fleft[s.top()] = 0;
        s.pop();
    }
    return;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        first[i] = first[i - 1] + a[i];
    }
    minRight(); minLeft();
    ll ans = -0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        // cout << fleft[i] << ' ' << fright[i] << endl;
        ans = max(ans, a[i] * (first[fright[i]] - first[fleft[i]]));
    }
    cout << ans << endl;
    return 0;
}