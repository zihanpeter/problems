#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e4 + 5;
int n, b, h[N];
bool cmp(int x, int y) { return x > y; }
int main() {
    scanf("%d%d", &n, &b);
    for (int i = 1; i <= n; ++i) scanf("%d", h + i);
	sort(h + 1, h + n + 1, cmp);
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		sum += h[i];
		if (sum >= b) {
			cout << i;
			return 0;
		}
	}
    return 0;
}
