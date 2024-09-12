#include <iostream>
using namespace std;
int main() {
    int n, tn, ans = 0, b = 0;
    cin >> n;
    while (n > 1) {
        ans += n / 2;
        tn = n;
        n = (n / 2 + b) / 3 + n % 2;
        b = (tn / 2 + b) % 3;
    }
    cout << ans;
    return 0;
}