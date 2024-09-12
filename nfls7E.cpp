#include <iostream>
#include <deque>
using namespace std;
const int N = 1e6 + 5;
int n, a[N], A, B, ans;
deque<int> q1, q2;
int main() {
    scanf("%d%d%d", &n, &A, &B);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    int l1 = -1, l2 = -1;
    for (int i = 0; i < n; ++i) {
        while (!q1.empty() && a[q1.back()] <= a[i]) q1.pop_back();
        while (!q2.empty() && a[q2.back()] >= a[i]) q2.pop_back();
        q1.push_back(i);
        q2.push_back(i);
        while (!q1.empty() && !q2.empty() && a[q1.front()] - a[q2.front()] > B) {
            if (q1.front() < q2.front()) {
                l1 = q1.front();
                q1.pop_front();
            } else {
                l2 = q2.front();
                q2.pop_front();
            }
        }
        if (!q1.empty() && !q2.empty() && a[q1.front()] - a[q2.front()] >= A) {
            ans = max(ans, i - max(l1, l2));
        }
    }
    printf("%d", ans);
    return 0;
}