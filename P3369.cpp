// FHQ Treap

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int root, x, y, z, cnt;
struct node {
	int v, num, l, r, size;
} tree[N << 2];

inline void update(int root) {
	tree[root].size = tree[tree[root].l].size + tree[tree[root].r].size + 1;
}

inline void split(int root, int v, int &x, int &y) {
	if (!root) {
		x = y = 0;
		return;
	}
	if (tree[root].v <= v) {
		x = root;
		split(tree[root].r, v, tree[root].r, y);
	} else {
		y = root;
		split(tree[root].l, v, x, tree[root].l);
	}
	update(root);
}

inline int merge(int x, int y) {
	if (!x || !y) return x + y;
	if (tree[x].num > tree[y].num) {
		tree[x].r = merge(tree[x].r, y);
		update(x);
		return x;
	} else {
		tree[y].l = merge(x, tree[x].l);
		update(y);
		return y;
	}
}

inline int newNode(int v) {
	tree[++cnt].v = v;
	tree[cnt].size = 1;
	tree[cnt].num = rand();
	return cnt;
}

inline void insert(int v) {
	split(root, v, x, y);
	root = merge(merge(x, newNode(v)), y);
}

inline void del(int v) {
	split(root, v, x, z);
	split(x, v - 1, x, y);
	y = merge(tree[y].l, tree[y].r);
	root = merge(merge(x, y), z);
}

inline int getRank(int v) {
	split(root, v - 1, x, y);
	int res = tree[x].size + 1;
	root = merge(x, y);
	return res;
}

inline int getVal(int x) {
	int cur = root;
	while (cur) {
		if (tree[tree[cur].l].size + 1 == x) break;
		else if (tree[tree[cur].l].size > x) cur = tree[cur].l;
		else {
			x -= tree[tree[cur].l].size + 1;
			cur = tree[cur].r;
		}
	}
	return tree[cur].v;
}

inline int getPre(int v) {
	split(root, v - 1, x, y);
	int cur = x;
	while (tree[cur].r) cur = tree[cur].r;
	root = merge(x, y);
	return tree[cur].v;
}

inline int getNxt(int v) {
	split(root, v, x, y);
	int cur = y;
	while (tree[cur].l) cur = tree[cur].l;
	root = merge(x, y);
	return tree[cur].v;
}

int main() {
	srand(time(NULL));
	int n, x, opt;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &opt, &x);
		if (opt == 1) {
			insert(x);
		} else if (opt == 2) {
			del(x);
		} else if (opt == 3) {
			printf("%d\n", getRank(x));
		} else if (opt == 4) {
			printf("%d\n", getVal(x));
		} else if (opt == 5) {
			printf("%d\n", getPre(x));
		} else if (opt == 6) {
			printf("%d\n", getNxt(x));
		}
	}
	return 0;
}