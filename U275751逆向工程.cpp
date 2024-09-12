#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int N = 1e2 + 5;
int n, m, res[N];
bool vis[N];
string s[N];
int main() {
	int T;
	cin >> T;
	while (T--) {
		memset(vis, 0, sizeof(vis));
		cin >> n >> m;
		for (int i = 1; i <= m; ++i) 
			cin >> s[i] >> res[i];
		for (int i = 1; i <= n; ++i) { // 访问每一位
			int notes0 = -1, notes1 = -1;
			bool yn0 = true, yn1 = true;
			// 0的寻找
			for (int j = 1; j <= m; ++j) {
				if (vis[j])
					continue; 
				if (s[j][i - 1] != '0') 
					continue;
				if (notes0 == -1) 
					notes0 = res[j];
				else if (notes0 != res[j]) {
					yn0 = false;
					break;
				}
			}
			// 1的寻找 
			for (int j = 1; j <= m; ++j) {
				if (vis[j])
					continue;
				if (s[j][i - 1] != '1') 
					continue;
				if (notes1 == -1) 
					notes1 = res[j];
				else if (notes1 != res[j]) {
					yn1 = false;
					break;
				}
			}
			// 判断能否成立条件并删边
			if (yn0 && yn1 && notes0 != notes1) // 01均可删
				for (int j = 1; j <= m; ++j) 
					vis[j] = true;
			else if (yn0) 
				for (int j = 1; j <= m; ++j) 
					if (s[j][i - 1] == '0') 
						vis[j] = true;
			else if (yn1) 
				for (int j = 1; j <= m; ++j) 
					if (s[j][i - 1] == '1') 
						vis[j] = true;	
		}
		bool mode = false;
		for (int i = 1; i <= m; ++i) 
			if (vis[i] == false) 
				mode = true;
		if (mode == false) {
			cout << "OK" << endl;
		} else {
			cout << "LIE" << endl;
		}
	}
	return 0;
} 
