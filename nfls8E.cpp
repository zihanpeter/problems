#include <iostream>
#include <deque>
using namespace std;
const int N = 5e5 + 5;
int n, k, a[N];
deque<int> q;

int main() {
    scanf("%d%d", &n, &k);
    getchar();
    // getchar();
    char c;
    for (int i = 1; i <= n; ++i) {
        c = getchar();
        a[i] = c - '0';
    }
    for (int i = 1; i <= n; ++i) {
        while (!q.empty() && a[i] > a[q.back()]) q.pop_back();
        q.push_back(i);
        if (i > k) {
            printf("%d", a[q.front()]);
            q.pop_front();
        }
    }
    return 0;
}