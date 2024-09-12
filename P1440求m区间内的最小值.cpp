#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int n, m, a[N];
deque<int> q;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) 
        scanf("%d", a + i);
    printf("0\n");
    for (int i = 1; i < n; ++i) {
    	while (!q.empty() && a[q.back()] > a[i])
    		q.pop_back();
    	while (!q.empty() && q.front() < (i - m + 1))
    		q.pop_front();
    	q.push_back(i);
    	printf("%d\n", a[q.front()]);
	}
    return 0;
}
