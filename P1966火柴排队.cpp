#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e8 - 3;
int n, a[N], b[N], c[N], ans;
map<int, int> dic;
void mergeSort(int l, int r) {
    if (l >= r) 
        return;
    int mid = (l + r) >> 1;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) 
        if (b[i] <= b[j]) 
            c[k++] = b[i++];
        else {
            c[k++] = b[j++];
            ans = (ans % mod + (mid - i + 1) % mod) % mod;
        }
    while (i <= mid)
        c[k++] = b[i++];
    while (j <= r) 
        c[k++] = b[j++];
    for ( ; l <= r; ++l) 
        b[l] = c[l];
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) 
        scanf("%d", a + i);
    for (int i = 1; i <= n; ++i) 
        scanf("%d", b + i);
    for (int i = 1; i <= n; ++i) 
        dic[a[i]] = i;
    for (int i = 1; i <= n; ++i) 
        b[i] = dic[b[i]];
    mergeSort(1, n);
    printf("%d", ans);
    return 0;
}