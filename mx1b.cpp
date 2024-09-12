#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
string s, t, anss, anst, ans;
int num[105];
vector<int> v;
bool flag = false;
void dfs(int l, int r) {
    if (l > r) return;
    if (l == r) {
        flag = true;
        return;
    }
    int id = l, maxf = s[l]; 
    for (int i = l + 1; i <= r; ++i) {
        if (s[i] > maxf) {
            id = i;
            maxf = s[i];
        }
    }
    v.push_back(id);
    dfs(id + 1, r);
}
void dfs2(int l, int r, int tc) {
    if (l > r) {
        string temp = "";
        for (int i = 1; i < tc; ++i) temp += s[num[i]];
        for (int i = 1; i < tc; ++i) temp += t[num[i]];
        if (temp > ans) ans = temp;
        return;
    }
    int maxf = s[l];
    for (int i = l + 1; i <= r; ++i) if (s[i] > maxf) maxf = s[i];
    for (int i = l; i <= r; ++i) {
        if (s[i] == maxf) {
            num[tc] = i;
            dfs2(i + 1, r, tc + 1);
            dfs2(i + 1, r, tc);
        }
    }
}
int main() {
    freopen("xiao.in", "r", stdin);
    freopen("xiao.out", "w", stdout);
    cin >> s >> t;
    if (s == t) {
        dfs(0, s.length() - 1);
        for (int i = 0; i < v.size(); ++i) {
            anss += s[v[i]];
            anst += t[v[i]];
        }
        string ans1 = anss + anst, ans2 = anss + s[s.length() - 1] + anst + t[s.length() - 1];
        if (ans1 > ans2) cout << ans1;
        else cout << ans2;
    } else {
        dfs2(0, s.length() - 1, 1);
        cout << ans;
    }
    return 0;
}