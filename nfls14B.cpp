#include <iostream>
#include <string>
using namespace std;
const int N = 1e6 + 5;
int n, p[N], ans;
string src, s = "+#";
void manacher() {
    for (int i = 0; i < src.length(); ++i) {
        s += src[i];
        s += '#';
    }
    s += '-';
    int r = 0, c = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (2 * c - i < c + r) p[i] = min(p[2 * c - i], c + r - i);
        while (s[i - p[i] - 1] == s[i + p[i] + 1]) ++p[i];
        if (i + p[i] > c + r) {
            c = i;
            r = p[i];
        }
        ans = max(ans, p[i]);
    }
    return;
}
int main() {
    cin >> n >> src;
    manacher();
    cout << ans;
    return 0;
}