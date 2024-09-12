#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, feel[N], l[N], r[N], sum[N];
stack<int> s;
priority_queue<long long> q;
int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) 
		cin >> feel[i];
	for (int i = 1; i <= n; ++i) 
		sum[i] = sum[i - 1] + feel[i];
	for (int i = 1; i <= n; ++i) {
		while (!s.empty() && feel[s.top()] > feel[i]) {
			r[s.top()] = i;
			s.pop();
		}
		if (!s.empty()) 
			l[i] = s.top();
		s.push(i);
	}
	for (int i = 1; i <= n; ++i) {
		if (r[i] == 0)
			r[i] = n + 1;
		--r[i];
		q.push(1ll * (sum[r[i]] - sum[l[i]]) * feel[i]);
	}
	cout << q.top() << endl;
	return 0;
}
