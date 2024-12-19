#include <iostream>
using namespace std;
const int N = 1e2 + 5;
int n, a[N];
double fd[N], fm[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	fd[1] = 100;
	fm[1] = a[1];
	for (int i = 2; i <= n; ++i) {
		fd[i] = max(fd[i - 1], fm[i - 1] * 100 / a[i]);
		fm[i] = max(fm[i - 1], fd[i - 1] * a[i] / 100);	
	}
	printf("%.2f", fd[n]);
	return 0;
}
