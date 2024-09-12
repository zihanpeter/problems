#include <bits/stdc++.h>
using namespace std;
int dic[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int n;
int sumer(int x) {
    if (x == 0) 
        return 6;
    int ans = 0;
    while (x > 0) {
        ans += dic[x % 10];
        x /= 10;
    }
    return ans;
}
bool check(int x, int y) {
    int bigSum = 4;
    bigSum += sumer(x);
    bigSum += sumer(y);
    bigSum += sumer(x + y);
    return bigSum == n;
}
int main() {
    cin >> n;
    int ans = 0;
    for (int i = 0; i <= 1000; ++i) {
        for (int j = 0; j <= 1000; ++j) {
            if (check(i, j)) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}