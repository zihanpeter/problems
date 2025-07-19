#include <bits/stdc++.h>
using namespace std;
const int N = 3e4 + 5;
int f[N], size[N], dis[N];

int find(int x) {
	if (x == f[x]) {
		return x;
	}
    int t = f[x];
	f[x] = find(f[x]);
	dis[x] += dis[t];
	size[x] = size[f[x]];
	return f[x];
}

void merge(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx != fy) {
		f[fx] = fy;
		dis[fx] = dis[fy] + size[fy];
		size[fy] += size[fx];
		size[fx] = size[fy];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 1; i <= 3e4; ++i) {
		f[i] = i;
		size[i] = 1;
		dis[i] = 0;
	}
	int t, x, y;
	cin >> t;
	char c; 
	for (int i = 1; i <= t; ++i) {
		cin >> c >> x >> y;
		if (c == 'M') merge(x, y);
		else 
			if (find(x) != find(y)) cout << "-1" << endl;
			else cout << abs(dis[y] - dis[x]) - 1 << endl;
	}
	return 0;
}