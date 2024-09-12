#include <iostream>
#include <string>
#include <map>
using namespace std;
typedef unsigned long long ull;
const int N = 116, BASE = 131;
bool vis[N][N];
string s[N];
int n, m, ans;
map<ull, bool> dic;
void dfs(int x, int y) {
  int mx = 0, my = 0;
  ull hashx = 0;
  for (int i = x; i <= n; ++i) {
    if (s[i][y] == '#') {
      break;
    }
    for (int j = y; j <= m; ++j) {
      if (s[i][j] == '#') {
        break;
      }
      mx = max(mx, i);
      my = max(my, j);
      vis[i][j] = true;
      hashx = hashx * 131 + s[i][j];
    }
  }
  if (dic.count(hashx)) 
    return;
  dic[hashx] = true;
  ++ans;
  hashx = 0;
  for (int j = y; j <= my; ++j) {
    for (int i = mx; i >= x; --i) {
      hashx = hashx * BASE + s[i][j];
    }
  }
  dic[hashx] = true;
  hashx = 0;
  for (int i = mx; i >= x; --i) {
    for (int j = my; j >= y; --j) {
      hashx = hashx * BASE + s[i][j];
    }
  }
  dic[hashx] = true;
  hashx = 0;
  for (int j = my; j >= y; --j) {
    for (int i = x; i <= mx; ++i) {
      hashx = hashx * BASE + s[i][j];
    }
  }
  dic[hashx] = true;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    s[i] = " " + s[i];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (s[i][j] != '#' && !vis[i][j]) {
        dfs(i, j);
      }
    }
  }
  cout << ans << endl;
  return 0;
}