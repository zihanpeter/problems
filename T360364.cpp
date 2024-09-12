#include <iostream>
using namespace std;
string s, t, p;
int x, y, i, j;

int main() {
	cin >> s >> t >> x >> y;
	while (true) {
		if (i <= s.length()) {
			p += s.substr(i, x);
			i += x;
		}
		if (j <= t.length()) {
			p += t.substr(j, y);
			j += y;
		}
		if (i > s.length() && j > t.length()) break;
	}
	cout << p;
	return 0;
}
