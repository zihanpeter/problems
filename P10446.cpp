#include <iostream>
using namespace std;
long long aa, bb, cc, res;
__int128_t a, b, c;

int main() {
    cin >> aa >> bb >> cc;
    a = aa, b = bb, c = cc;
    res = (a % c * (b % c)) % c;
    cout << res;
    return 0;
}