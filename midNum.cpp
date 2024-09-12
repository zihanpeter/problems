// 中位数
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, a[N];
priority_queue<int, vector<int>, greater<int> > q1; // 存放 > mid
priority_queue<int> q2; // 存放 <= mid
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) 
        scanf("%d", a + i) ;
    int mid = a[1];
    printf("%d\n", mid);
    for (int i = 3; i <= n; i += 2) {
        if (a[i] > mid) 
            q1.push(a[i]);
        else
            q2.push(a[i]); 
        if (a[i - 1] > mid) 
            q1.push(a[i - 1]);
        else
            q2.push(a[i - 1]); 
        if (q1.size() < q2.size()) {
            while (q1.size() != q2.size()) {
                q1.push(mid);
                mid = q2.top();
                q2.pop();
            }
        } else if (q1.size() > q2.size()) {
            while (q1.size() != q2.size()) {
                q2.push(mid);
                mid = q1.top();
                q1.pop();
            }
        }
        printf("%d\n", mid);
    }
    return 0;
}