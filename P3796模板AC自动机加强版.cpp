#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1e4 + 5;
int trie[N][26], last, cnt[N], tong[N], fail[N];
string save[155];
void insert(string s, int num) {
    int x = 0;
    for (int i = 0; i < s.length(); ++i) {
        int y = s[i] - 'a';
        if (!trie[x][y]) {
            trie[x][y] = ++last;
        }
        x = trie[x][y];
    }
    cnt[x] = num;
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
    while (x) {
        ans += cnt[x];
        ++tong[cnt[x]];
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
    while (true) {
        memset(trie, 0, sizeof(trie));
        memset(cnt, 0, sizeof(cnt));
        memset(tong, 0, sizeof(tong));
        memset(fail, 0, sizeof(fail));
        last = 0;
        string s, p;
        int m;
        cin >> m;
        if (m == 0) {
            break;
        }
        for (int i = 1; i <= m; ++i) {
            
            cin >> p;
            insert(p, i);
			save[i] = p;
        }
        cin >> s;
        build();
        query(s);
        int maxf = -0x3f3f3f3f;
        for (int i = 1; i <= m; ++i) {
            maxf = max(maxf, tong[i]);
        }
        cout << maxf << endl;
        for (int i = 1; i <= m; ++i) {
            if (tong[i] == maxf) {
                cout << save[i] << endl;
            }
        }
    }
    return 0;
}