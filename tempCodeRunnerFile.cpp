#include <iostream>
using namespace std;

int main() {
    __int128 a, b, c;
    long long aa, bb, cc;
    cin >> aa >> bb >> cc;
    a = aa, b = bb, c = cc;
    long long res = aa * bb % cc;
    cout << res;
    return 0;
}