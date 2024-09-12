#include <iostream>
using namespace std;
int a[5000005], b[5000005];
int n;
void mergeSort(int l, int r){
    if (l == r) return;
    int mid = (l + r) / 2;
    mergeSort(l, mid);
    mergeSort(mid+1, r);
    int i = l, j = mid+1, k = l;
    while (i <= mid && j <= r){
        if (a[i] <= a[j]){
            b[k++] = a[i++];
        }else{
            b[k++] = a[j++];
        }
    }
    while (i <= mid) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];
    for (int i = l;i <= r;i++){
        a[i] = b[i];
    }
    return;
}
int main(){
    cin>>n;
    for (int i = 1;i <= n;i++){
        cin>>a[i];
    }
    mergeSort(1, n);
    for (int i = 1;i <= n;i++){
        cout<<a[i]<<' ';
    }
    return 0;
}