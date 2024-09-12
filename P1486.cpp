#include <iostream>
#include <ctime>
using namespace std;
const int N = 1e7 + 5;
int root, cnt, n, minf, delta;
struct node {
	int v, num, l, r, size;
} tree[N];
void update(int root) {
	tree[root].size = tree[tree[root].l].size + tree[tree[root].r].size + 1;
}
void split(int root, int v, int &x, int &y) {
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
int merge(int x, int y) {
	if (!x || !y) return x + y;
	if (tree[x].num > tree[y].num) {
		tree[x].r = merge(tree[x].r, y);
		update(x);
		return x;
	} else {
		tree[y].l = merge(x, tree[y].l);
		update(y);
		return y;
	}
}
int newNode(int v) {
	tree[++cnt].v = v;
	tree[cnt].size = 1;
	tree[cnt].num = rand();
	tree[cnt].l = tree[cnt].r = 0;
	return cnt;
}
void insert(int v) {
	int x, y;
	split(root, v, x, y);
	root = merge(merge(x, newNode(v)), y);
}
void del(int v) {
	int x, y;
    split(root, v, x, y);
    root = y;
}
int getVal(int root, int x) {
	if (x == tree[tree[root].l].size + 1) return root;
	if (x <= tree[tree[root].l].size) return getVal(tree[root].l, x);
	if (x > tree[tree[root].l].size) return getVal(tree[root].r, x - tree[tree[root].l].size - 1);
}
int main() {
	srand(time(NULL));
	scanf("%d%d", &n, &minf);
    char x;
    int k;
    while (n--) {
        scanf("%c%d", &x, &k);
        if (x == 'I') if (k - delta >= minf) insert(k - delta);
        else if (x == 'A') {
            delta += k;
        } else if (x == 'S') {
            delta -= k;
            del(minf - delta);
        } else if (x == 'F') {
            printf("%d\n", tree[getVal(root, k)].v + delta);
        }
    }
	return 0;
}