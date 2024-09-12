#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, t = 0;
	scanf("%d", &n);
	for (int i = n; i; --i) {
		for (int j = 1; j <= i; ++j) 
			if (++t < 10) printf("0%d", t);
			else printf("%d", t);
		printf("\n");
	}
	return 0;
}