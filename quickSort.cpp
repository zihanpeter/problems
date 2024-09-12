#include <iostream>
using namespace std;
int a[1000005];
int n;
void quickSort(int l, int r){
    if (l >= r){
        return;
    }
    int temp = a[l];
    bool flag = false;
    int i = l, j = r;
    while (i != j){
        if (flag == true){
            if (a[i] > temp){
                a[j] = a[i];
                flag = false;
            }
            if (flag == true) ++i;
        }else{
            if (a[j] < temp){
                a[i] = a[j];
                flag = true;
            }
            if (flag == false) --j;
        }
    }
    a[i] = temp;
    quickSort(l, i-1);
    quickSort(i+1, r);
}
int main(){
    cin>>n;
    for (int i = 1;i <= n;i++){
        cin>>a[i];
    }
    quickSort(1, n);
    for (int i = 1;i <= n;i++){
        cout<<a[i]<<' ';
    }
    return 0;
}