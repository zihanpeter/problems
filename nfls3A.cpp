#include <iostream>
#include <cmath>
using namespace std;
int a, b, x, y;
int main() {
    scanf("%d%d%d%d", &a, &b, &x, &y);
    if (a > b) swap(a, b);
    if (x > y) swap(x, y);
    int ans = abs(a - b);
    ans = min(ans, abs(a - x) + abs(b - y));
    ans = min(ans, abs(a - y) + abs(b - x));
    printf("%d", ans);
    return 0;
}