#include <iostream>
using namespace std;
const int N = 20;
int n, k, a[N];

void dfs(int t, int sum) {
  if (t == n + 1) {
    if (sum == k) {
      printf("Yes");
      exit(0);
    }
    return;
  }
  dfs(t + 1, sum + a[t]);
  dfs(t + 1, sum);
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  dfs(1, 0);
  printf("No");
  return 0;
}