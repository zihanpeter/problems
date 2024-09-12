#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, tong[100005], inf = 0x3f3f3f3f;
queue<ll> q1, q2;
inline ll read() {
    ll x = 0, w = 0;
    char ch = 0;
    while (!isdigit(ch)) {
        w |= (ch == '-');
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return w ? -x : x;
}
int main() {
	n = read();
	ll t;
	for (ll i = 1; i <= n; ++i) {
		t = read();
		++tong[t];
	}
	for (ll i = 0; i <= 1e5; ++i) 
		while (tong[i] > 0) {
			tong[i]--;
			q1.push(i);
		}	
	ll ans = 0;
	while (!(q1.size() == 0 && q2.size() == 1)) {
		ll ta, tb;
		if (!q1.empty() && !q2.empty()) {
			if (q1.front() < q2.front()) {
				ta = q1.front();
				q1.pop();
			} else {
				ta = q2.front();
				q2.pop();
			}
		} else {
			if (!q1.empty()) {
				ta = q1.front();
				q1.pop();
			} else {
				ta = q2.front();
				q2.pop();
			}
		}
		if (!q1.empty() && !q2.empty()) {
			if (q1.front() < q2.front()) {
				tb = q1.front();
				q1.pop();
			} else {
				tb = q2.front();
				q2.pop();
			}
		} else {
			if (!q1.empty()) {
				tb = q1.front();
				q1.pop();
			} else {
				tb = q2.front();
				q2.pop();
			}
		}
		ans += ta + tb;
		q2.push(ta + tb);
	}
	printf("%lld", ans);
	return 0;
}
