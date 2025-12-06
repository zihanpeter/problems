#include <iostream>
using namespace std;
int main() {
    string s, t = "";
    int cnt = 0;
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = 'a' + s[i] - 'A';
        }
        t += s[i];
        if (t[i] == '.') {
            cnt++;
            if (t[i - 1] == '.') {
                return 0;
            }
        }
        if (i >= 6 && t.substr(i - 6, i + 1) == ".edu.cn") {
            cout << i + 1 << ' ';
        }
    }
    return 0;
}
