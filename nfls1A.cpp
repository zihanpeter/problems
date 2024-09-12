#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, c[N], sum2;
string s[N];
double sum1, ans;
map<string, double> dic;
int main() {
	dic["A"] = 4.0;
	dic["A-"] = 3.7;
	dic["B+"] = 3.3;
	dic["B"] = 3.0;
	dic["B-"] = 2.7;
	dic["C+"] = 2.3;
	dic["C"] = 2.0;
	dic["C-"] = 1.7;
	dic["D"] = 1.3;
	dic["D-"] = 1.0;
	dic["F"] = 0.0; 
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i] >> s[i];
	}
	for (int i = 1; i <= n; ++i) {
		if (s[i] == "P" || s[i] == "N") continue;
		sum1 += c[i] * dic[s[i]];
		sum2 += c[i];
	}
	if (sum2 != 0) ans = sum1 / sum2;
	cout << fixed << setprecision(2) << ans;
	return 0;
} 
