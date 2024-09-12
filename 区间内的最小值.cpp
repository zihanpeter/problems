#include <iostream>
#include <deque>
using namespace std;
const int N = 2e6 + 5;
int a[N];
int main() {
    int n, m;
    deque<int> q;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    //printf("0\n");
    for (int i = 1; i <= n; i++) {
        while (!q.empty() && q.front() < i - m) q.pop_front();
        if (q.size() == 0) {
            printf("0\n");
        } else {
            printf("%d\n", a[q.front()]);
        }
        while (!q.empty() && a[q.back()] >= a[i]) q.pop_back();
        q.push_back(i);
    }
    return 0;
}