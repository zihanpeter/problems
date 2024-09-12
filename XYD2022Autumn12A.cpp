#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e6 + 5;
int nxt[N], n, m;
string s, t;
vector<string> v;
void initNext() {
    nxt[1] = 0;
    for (int cur = 1, now; cur < m; ++cur) {
        now = nxt[cur];
        while (now > 0 && t[cur + 1] != t[now + 1]) {
            now = nxt[now];
        }
        if (t[cur + 1] == t[now + 1]) {
            nxt[cur + 1] = now + 1;
        } else {
            nxt[cur + 1] = 0;
        }
    }
}
bool kmp() {
    for (int cur = 1, now = 0; cur <= n; ++cur) {
        while (now > 0 && s[cur] != t[now + 1]) {
            now = nxt[now];
        }
        if (s[cur] == t[now + 1]) {
            ++now;
        }
        if (now == m) {
            return true;
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num;
    cin >> num >> t;
    m = t.length();
    t = "0" + t;
    for (int i = 1; i <= num; ++i) {
        cin >> s;
        n = s.length();
        s = "0" + s;
        if (kmp()) {
            v.push_back(s.substr(1, n));
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }
    return 0;
}