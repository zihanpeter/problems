#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5e6 + 5;
int n, k, a[N];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    sort(a, a + n);
    printf("%d", a[k]);
    return 0;
}