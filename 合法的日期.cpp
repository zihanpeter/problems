#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int days[13] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
bool check(string s) {
	int info[4], cnt = 1;
	memset(info, 0, sizeof(info));
	for (int i = 0; i < s.length(); ++i) 
		if (s[i] == '/') 
			++cnt;
		else 
			info[cnt] = (info[cnt] * 10) + (s[i] - '0');
	if (info[2] > 12) 
		return false;
	if (info[3] <= 0) 
		return false;
	if (info[2] == 2) {
		if (info[1] % 400 == 0 || (info[1] % 4 == 0 && info[1] % 100 == 0)) {
			if (info[3] > 29) {
				return false;
			}
		} else 
			if (info[3] > 28) 
				return false;
	} else 
		if (info[3] > days[info[2]]) 
			return false;
	return true;
}
void dfs(int t, string s) {
	if (t > s.length()) {
		if (check(s))
			cout << s << endl;
		return;
	}
	if (s[t] != '?') {
		dfs(t + 1, s);
		return;
	}
	for (int i = 0; i <= 9; ++i) {
		s[t] = char('0' + i);
		dfs(t + 1, s);
	}
	return;
}
int main() {
	string s;
	cin >> s;
	dfs(0, s);
	return 0;
}
