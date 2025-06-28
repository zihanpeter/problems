#include <iostream>
using namespace std;
int n, t, ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &t);
        ans ^= t;
    }
    printf("%d", ans);
    return 0;
}