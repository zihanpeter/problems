#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e6 + 5;
int nxt[N];
char s[N], t[N];
void initNext(char *t) {
	nxt[1] = 0;
	int m = strlen(t);
	for (int cur = 1, now; cur < m; ++cur) {
		now = nxt[cur];
		while (now > 0 && t[cur + 1] != t[now + 1]) {
			now = nxt[now];
		}
		if (t[cur + 1] == t[now + 1]) {
			nxt[cur + 1] = now + 1;
		} else {
			nxt[cur + 1] = 0;
		}
	} 
}
void kmp(char *s, char *t) {
	int n = strlen(s), m = strlen(t);
	for (int cur = 1, now = 0; cur <= n; ++cur) {
		while (now > 0 && s[cur] != t[now + 1]) {
			now = nxt[now];
		}
		if (s[cur] == t[now + 1]) {
			++now;
		}
		if (now == m) {
			printf("%d", cur - m + 1);
			now = nxt[now];
		}
	}
}
int main() {
	
	return 0;
}
