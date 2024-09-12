#include <iostream>
#include <string>
#include <queue>
using namespace std;
const int N = 1e6 + 5;
int trie[N][26], last, cnt[N], fail[N];
void insert(string p) {
    int x = 0;
    for (int i = 0; i < p.length(); ++i) {
        int y = p[i] - 'a';
        if (!trie[x][y]) {
            trie[x][y] = ++last;
        }
        x = trie[x][y];
    }
    ++cnt[x];
}
void build() {
    queue<int> q;
    for (int i = 0; i < 26; ++i) {
        if (trie[0][i]) {
            q.push(trie[0][i]);
        }
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < 26; ++i) {
            if (trie[x][i]) {
                fail[trie[x][i]] = trie[fail[x]][i];
                q.push(trie[x][i]);
            } else {
                trie[x][i] = trie[fail[x]][i];
            }
        }
    }
}
int calc(int x) {
    int ans = 0;
    while (x && ~cnt[x]) {
        ans += cnt[x];
        cnt[x] = -1;
        x = fail[x];
    }
    return ans;
}
int query(string s) {
    int x = 0, ans = 0;
    for (int i = 0; i < s.length(); ++i) {
        int y = s[i] - 'a';
        x = trie[x][y];
        ans += calc(x);
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    int m;
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        string p;
        cin >> p;
        insert(p);
    }
    cin >> s;
    build();
    cout << query(s);
    return 0;
}