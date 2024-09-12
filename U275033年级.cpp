#include <bits/stdc++.h>
using namespace std;
int main() {
    int d, y, m, a, b;
    cin >> d >> y >> m >> a >> b;
    int ans = d + a - y;
    if (m < 9) 
        ++ans;
    if (b < 9) 
        --ans;
    if (ans <= 12) 
        cout << ans << endl;
    else if (ans > 12 && ans <= 15) 
        cout << "college" << endl;
    else 
        cout << "graduate" << endl;
    return 0;
}