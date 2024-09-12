#include <bits/stdc++.h>
using namespace std;
int main() {
    double a;
    cin >> a;
    int cnt = 0;
    for (int i = 3; i >= 1; --i) {
        int res = a * pow(10, i);
        if (res % 10 == 0) {
            ++cnt;
        } else break;
    }
    cnt = 3 - cnt;
    cout << fixed << setprecision(cnt) << a;
    return 0;
}