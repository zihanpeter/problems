#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5e4 + 5;
int n, m, a[N], tree[N << 2], pos[N], tong[N];
struct node {
	int x, y, id, ans;
} offLine[N];
bool cmp(node x, node y) {
	return x.y < y.y;
}
bool cmp2(node x, node y) {
	return x.id < y.id;
}
void pushUp(int id) {
	tree[id] = tree[id << 1] + tree[id << 1 | 1];
}
void build(int id, int l, int r) {
	if (l == r) {
		tree[id] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid + 1, r);
	pushUp(id);
}
void update(int id, int l, int r, int x, int y) {
	if (l == r) {
		tree[id] = y;
		return;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) 
		update(id << 1, l, mid, x, y);
	else
		update(id << 1 | 1, mid + 1, r, x, y);
	pushUp(id);
}
int query(int id, int l, int r, int L, int R) {
	if (L <= l && r <= R) 
		return tree[id];
	int mid = (l + r) >> 1, ans = 0;
	if (L <= mid) 
		ans += query(id << 1, l, mid, L, R);
	if (R > mid)
		ans += query(id << 1 | 1, mid + 1, r, L, R);
	return ans;	
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) 
        cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i <= n; ++i) 
        if (tong[a[i]] == 0) {
        	pos[i] = i;
        	tong[a[i]] = i;
		} else {
			pos[i] = tong[a[i]];
			tong[a[i]] = i;
		}
    cin >> m;
    for (int i = 1; i <= m; ++i) {
    	cin >> offLine[i].x >> offLine[i].y;
    	offLine[i].id = i;
    }
	sort(offLine + 1, offLine + 1 + m, cmp);
	int end = 1;
	for (int i = 1; i <= m; ++i) {
		for (int j = end; j <= offLine[i].y; ++j) {
			if (pos[j] != j) {
				update(1, 1, n, j, 0);
				pos[a[j]] = j;
			}
		}
		end = offLine[i].y;
		offLine[i].ans = query(1, 1, n, offLine[i].x, offLine[i].y);
	}
	sort(offLine + 1, offLine + m + 1, cmp2);
	for (int i = 1; i <= m; ++i) 
		cout << offLine[i].ans << endl;
    return 0;
}
