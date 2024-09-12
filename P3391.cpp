#include <iostream>
#include <ctime>
using namespace std;

const int N = 1e5 + 5;

int cnt, root, n, m;

struct node {
    int l, r, v, p, size, rev;
} tree[N];

int newNode(int v) {
    tree[++cnt].v = v;
    tree[cnt].p = rand();
    tree[cnt].size = 1;
    return cnt;
}

void update(int id) {
    tree[id].size = tree[tree[id].l].size + tree[tree[id].r].size + 1;
}

void pushDown(int id) {
    swap(tree[id].l, tree[id].r);
    tree[id].rev = 0;
    tree[tree[id].l].rev ^= 1;
    tree[tree[id].r].rev ^= 1;
}

void split(int id, int size, int &x, int &y) {
    if (!id) {
        x = y = 0;
        return;
    }
    if (tree[id].rev) pushDown(id);
    if (tree[tree[id].l].size < size) {
        x = id;
        split(tree[id].r, size - tree[tree[id].l].size - 1, tree[id].r, y);
    } else {
        y = id;
        split(tree[id].l, size, x, tree[id].l);
    }
    update(id);
}

int merge(int x, int y) {
    if (!x || !y) return x + y;
    if (tree[x].p < tree[y].p) {
        if (tree[x].rev) pushDown(x);
        tree[x].r = merge(tree[x].r, y);
        update(x);
        return x;
    } else {
        if (tree[y].rev) pushDown(y);
        tree[y].l = merge(x, tree[y].l);
        update(y);
        return y;
    }
}

void reverse(int l, int r) {
    int x, y, z;
    split(root, l - 1, x, y);
    split(y, r - l + 1, y, z);
    tree[y].rev ^= 1;
    root = merge(merge(x, y), z);
}

void dfs(int id) {
    if (!id) return;
    if (tree[id].rev) pushDown(id);
    dfs(tree[id].l);
    printf("%d ", tree[id].v);
    dfs(tree[id].r);
}

int main() {
    srand(time(NULL));
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) root = merge(root, newNode(i));
    int l, r;
    while (m--) {
        cin >> l >> r;
        reverse(l, r);
    }
    dfs(root);
    return 0;
}