#include <bits/stdc++.h>
using namespace std;
const int N = 3e4 + 5;
int w, n;
string s[N];
map<string, int> dic;
bool check(int pos, string t) {
    if (s[pos].length() < t.length()) return false;
    for (int i = 0; i < t.length(); ++i) 
        if (s[pos][i] != t[i]) return false;
    return true;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> w >> n;
    for (int i = 1; i <= w; ++i) {
        cin >> s[i];
        dic[s[i]] = i;
    }
    sort(s + 1, s + w + 1);
    string t;
    int k;
    for (int i = 1; i <= n; ++i) {
        cin >> k >> t;
        int pos = lower_bound(s + 1, s + w + 1, t) - s + k - 1;
        if (check(pos, t)) cout << dic[s[pos]] << '\n';
        else cout << "-1\n";
    }
    return 0;
}