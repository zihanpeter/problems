#include <iostream>
using namespace std;
int a[1000005];
int main(){
    int n, m;
    cin>>n>>m;
    for (int i = 1;i <= n;i++){
        cin>>a[i];
    }
    int head = 1, tail = n;
    while (head < tail){
        int mid = (head + tail) / 2;
        if (a[mid] < m){
            head = mid + 1;
        }else{
            tail = mid;
        }
    }
    if (a[head] == m){
        cout<<head;
    }else{
        cout<<0;
    }
    return 0;
}