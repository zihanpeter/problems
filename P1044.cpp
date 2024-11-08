#include <iostream>
using namespace std;
int n, res[20][20];

int f(int x, int y) { // 栈内元素
    if (res[x][y]) return res[x][y];
    if (y) {
        res[x - 1][y + 1] = f(x - 1, y + 1);
        res[x][y - 1] = f(x, y - 1);
        return res[x - 1][y + 1] + res[x][y - 1];
    }
    return res[x - 1][y - 1] = f(x - 1, y + 1);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) res[0][i] = 1;
    printf("%d", f(n, 0));
    return 0;
}