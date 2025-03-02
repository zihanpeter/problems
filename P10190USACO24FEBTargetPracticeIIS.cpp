#include <iostream>
using namespace std;
const int N = 4e4 + 5;
int n, x1, y1[N], y2[N], x2[N], posi[N], posn, nega[N], negn;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> x1;
        for (int i = 1; i <= n; ++i) {
            cin >> y1[i] >> y2[i] >> x2[i];
        }
        for (int i = 1; i <= 4 * n; ++i) {
            int s;
            cin >> s;
            if (s > 0) {
                posi[++posn] = s;
            } else nega[++negn] = s;
        }
        for (int i = 1; i <= n; ++i) {
            
        }
    }
    return 0;
}