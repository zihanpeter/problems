#include <iostream>
#include <string>
#include <cstring>
#include <map>
using namespace std;
const int N = 3e6 + 5;
int n, m;
bool tong[N];
struct node {
    int w, id;
};
map<string, node> dic;
string s, temp;
int main() {
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    getline(cin, s);
    for (int i = 1; i <= n; ++i) {
        getline(cin, s);
        temp = "";
        bool flag = false;
        int t = 0;
        for (int j = 0; j < s.length(); ++j) {
            if (s[j] == ' ') { 
                flag = true;
                continue;
            }
            if (!flag) 
                temp += s[j];
            else 
                t = t * 10 + (s[j] - '0');
        }
        // cout << temp << ' ' << t << endl;
        dic[temp] = node{t, i};
    }
    cin >> m;
    while (m--) {
        // memset(tong, 0, sizeof(tong));
        long long ans = 0;
        temp = "";
        int cnt = 0;
        cin >> cnt;
        
        for (int i = 1; i <= cnt; ++i) {
            cin >> s;
            if (ans == -1) 
                continue;
            if (dic.count(s) == 0) {
                ans = -1;
                continue;
            }
                // tong[dic[s].id] = true;
                ans += dic[s].w;
            
        }
        cout << ans << endl;
    }
    return 0;
}