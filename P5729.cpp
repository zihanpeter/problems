#include <bits/stdc++.h>
using namespace std;
int v[25][25][25];
int main() {
	int w, x, h, q;
	cin >> w >> x >> h >> q;
	memset(v, 1, sizeof(v));
	while (q--) {
		int a, b, c, d, e, f;
		cin >> a >> b >> c >> d >> e >> f;
		for (int i = min(a, d); i <= max(a, d); ++i) 
			for (int j = min(b, e); j <= max(b, e); ++j) 
				for (int k = min(c, f); k <= max(c, f); ++k) 
					v[i][j][k] = 0;
	}
	int ans = 0;
	for (int i = 1; i <= w; ++i) 
		for (int j = 1; j <= x; ++j) 
			for (int k = 1; k <= h; ++k) 
				if (v[i][j][k]) ++ans;
	cout << ans; 
	return 0;
}