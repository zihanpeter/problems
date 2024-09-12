#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int N = 3e6 + 5;
int n, q, trie[N][64], last, cnt[N];
int getNum(char c) 
{
    if ('A' <= c && c <= 'Z') {
        return 26 + c - 'A';
    } 
    if ('a' <= c && c <= 'z') {
        return c - 'a';
    }
    if ('0' <= c && c <= '9') {
        return 2 * 26 + c - '0';
    } 
}
void insert(string s) 
{
    int fa = 0;
    for (int i = 0; i < s.length(); ++i) {
        int num = getNum(s[i]);
        if (!trie[fa][num]) {
            trie[fa][num] = ++last;
        }
        ++cnt[trie[fa][num]];
        fa = trie[fa][num];
    }
}
int find(string s) 
{
    int fa = 0;
    for (int i = 0; i < s.length(); ++i) {
        int num = getNum(s[i]);
        if (!trie[fa][num]) {
            return 0;
        }
        fa = trie[fa][num];
    }
    return cnt[fa];
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i <= last; ++i) {
            for (int j = 0; j <= 63; ++j) {
                trie[i][j] = 0;
            }
            cnt[i] = 0;
        }
        last = 0;
        cin >> n >> q;
        string s;
        for (int i = 1; i <= n; ++i) {
            cin >> s;
            insert(s);
        }
        for (int i = 1; i <= q; ++i) {
            cin >> s;
            cout << find(s) << endl;
        }
    }
    return 0;
}