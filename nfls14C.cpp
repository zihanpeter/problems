#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 1e3 + 5, B1 = 127, B2 = 137;
int n, m, a, b, q;
ull h[N][N], p1 = 1, p2 = 1;
string s[N], p[N];
map<ull, bool> dic;

void calc_hash() {
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j) 
			h[i][j] = h[i - 1][j] * B1 + h[i][j - 1] * B2 - h[i - 1][j - 1] * B1 * B2 + s[i][j];
}

void calc_hash2() {
	for (int i = 1; i <= a; ++i) 
		for (int j = 1; j <= b; ++j) 
			h[i][j] = h[i - 1][j] * B1 + h[i][j - 1] * B2 - h[i - 1][j - 1] * B1 * B2 + p[i][j];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> a >> b;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		s[i] = " " + s[i];
	}
	calc_hash();
    for (int i = 1; i <= a; ++i) p1 *= B1;
    for (int i = 1; i <= b; ++i) p2 *= B2;
    for (int i = a; i <= n; ++i) 
        for (int j = b; j <= m; ++j) 
            dic[h[i][j] - h[i - a][j] * p1 - h[i][j - b] * p2 + h[i - a][j - b] * p1 * p2] = true;
	cin >> q;
	while (q--) {
		for (int i = 1; i <= a; ++i) {
            cin >> p[i];
            p[i] = " " + p[i];
        }
        calc_hash2();
        if (dic.count(h[a][b])) cout << "1\n";
        else cout << "0\n";
    }
}
