#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[10];
ll ans = 0;
void dfsResolve(int t, int sum) {
    if (t == 4) {
        int temp = 0 - sum;
        if (a[t] == 0) {
            if (sum == 0)
                ans += 200;
            return;
        }
        if (temp % a[t] == 0) {
            if (temp / a[t] <= 0)
                return;
            int temp2 = sqrt(temp / a[t]);
            if (temp2 >= -100 && temp2 <= 100 && temp2 * temp2 == temp / a[t]) 
                ans += 2;
        }
        return;
    }
    for (int i = -100; i <= 100; ++i) {
        if (i == 0) 
            continue;
        dfsResolve(t + 1, sum + (a[t] * i * i));
    }
    return;
}
int main() {
    scanf("%d%d%d%d", &a[1], &a[2], &a[3], &a[4]);
    dfsResolve(1, 0);
    printf("%lld", ans);
    return 0;
}