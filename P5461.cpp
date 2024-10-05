#include <iostream>
using namespace std;
const int N = 1024 + 5;

int n, a[N][N];

void fill(int lx, int ly, int rx, int ry) {
    for (int i = lx; i <= rx; ++i) for (int j = ly; j <= ry; ++j) 
        a[i][j] = 0;
}

void tagger(int lx, int ly, int rx, int ry) {
    int tx = lx + (rx - lx + 1) / 2 - 1, ty = ly + (ry - ly + 1) / 2 - 1;
    fill(lx, ly, tx, ty);
    if (lx == rx && ly == ry) return;
	tagger(lx, ty + 1, tx, ry);
	tagger(tx + 1, ly, rx, ty);
	tagger(tx + 1, ty + 1, rx, ry);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= 1 << n; ++i) for (int j = 1; j <= 1 << n; ++j) a[i][j] = 1;
    tagger(1, 1, 1 << n, 1 << n);
	for (int i = 1; i <= 1 << n; ++i) {
		for (int j = 1; j <= 1 << n; ++j) printf("%d ", a[i][j]);
		printf("\n");
	}
    return 0;
}
