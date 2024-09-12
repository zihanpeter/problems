#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e6 + 5;
int next[N], n, m;
char s[N], t[N];
void initNext() {
	next[1] = 0;
	for (int cur = 1, now; cur < m; ++cur) {
		now = next[cur];
		while (now > 0 && t[cur + 1] != t[now + 1]) {
			now = next[now];
		}
		if (t[cur + 1] == t[now + 1]) {
			next[cur + 1] = now + 1;
		} else {
			next[cur + 1] = 0;
		}
	} 
}
void kmp() {
	for (int cur = 1, now = 0; cur <= n; ++cur) {
		while (now > 0 && s[cur] != t[now + 1]) {
			now = next[now];
		}
		if (s[cur] == t[now + 1]) {
			++now;
		}
		if (now == m) {
			printf("%d\n", cur - m + 1);
			now = next[now];
		}
	}
}
int main() {
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	n = strlen(s + 1);
	m = strlen(t + 1);
	initNext();
	kmp();
	for (int i = 1; i <= m; ++i) {
		printf("%d ", next[i]);
	}
	return 0;
}
