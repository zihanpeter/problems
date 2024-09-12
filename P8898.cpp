#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, k;
char s[N], as[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k); scanf("%s", s + 1);
        int H = 0, G = 0, ans = 0;
        memset(as, '.', sizeof(as));
        for (int i = 1; i <= n; ++i) 
            if (s[i] == 'H' && H < i) 
                for (int j = i + k < n ? i + k: n; j; --j) {
                	if (as[j] == '.') {
                		as[j] = 'H';
                		H = j + k;
                		++ans;
                		break;
					}
                }
            else if (s[i] == 'G' && G < i) 
               	for (int j = i + k < n ? i + k: n; j; --j) 
                	if (as[j] == '.') {
                		as[j] = 'G';
                		++ans;
                		G = j + k;
                		break;
					}
        printf("%d\n", ans);
        for (int i = 1; i <= n; ++i) printf("%c", as[i]);
		printf("\n"); 
    }
    return 0;
}