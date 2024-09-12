#include <cstdio>
using namespace std;
const int N = 1e5 + 5;
int n, a[N], b[N], cnt, ans = 1;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        if (a[i] != a[i - 1]) 
            b[++cnt] = a[i];
    }
    int rate = 0;
    if (b[2] > b[1]) 
        rate = 1;
    else 
        rate = -1;
    for (int i = 3; i <= cnt; ++i) {
        if (b[i] > b[i - 1] && rate != 1) {
            ++ans;
            rate = 1;
        } else if (b[i] < b[i - 1] && rate != -1) {
            ++ans;
            rate = -1;
        }
    }
    printf("%d", ans + 1);
    return 0;
}