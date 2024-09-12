#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, a[N], b[N], ans;
void mergeSort(int l, int r) {
    if (l >= r) {
        return;
    }
    int mid = (l + r) >> 1;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
            ans += mid - i + 1;
        }
    }
    while (i <= mid) {
        b[k++] = a[i++];
    }
    while (j <= r) {
        b[k++] = a[j++];
    }
    for ( ; l <= r; ++l) {
        a[l] = b[l];
    }
}
signed main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    mergeSort(1, n);
    cout << ans << endl;
    return 0;
}