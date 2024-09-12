#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
ll m;
int main() {
    cin >> m;
    for (ll i = 1e7; i >= 2; --i) {
        if (i % 2 == 0) {
            ll mid = (m / i);
            if (mid - (i / 2 - 1) <= 0) 
                continue;
            if ((mid - (i / 2 - 1) + mid + (i / 2)) * i / 2 != m) 
                continue;
            cout << mid - (i / 2 - 1) << ' ' << mid + (i / 2) << endl;
        } else {
            ll mid = (m / i);
            if (mid - (i / 2) <= 0) 
                continue;
            if ((mid - (i / 2) + mid + (i / 2)) * i / 2 != m) 
                continue;
            cout << mid - (i / 2) << ' ' << mid + (i / 2) << endl;
        }
    }
    return 0;
}