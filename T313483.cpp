#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll a[4], ans;
bool flag;
int main() {
	cin >> s;
	int t = 0;
	for (int i = 0; i < s.length(); ++i) 
		if (s[i] >= '0' && s[i] <= '9') a[t] = a[t] * 10 + s[i] - '0';
		else {
			if (s[i] == '>') flag = true;
			++t;
		}
	if (flag) ans = 2147483647 - a[3];
	else ans = a[3] + 2147483648;
	cout << ans;
	return 0;
}
