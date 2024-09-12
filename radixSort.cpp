#include <iostream>
#include <cstring>
using namespace std;
int a[1000005];
int f[10][1000005];
int main(){
    int n;
    int wei = 0;
    int k = 1;
    cin>>n;
    int max = -0x3f3f3f3f;
    for (int i = 1;i <= n;i++){
        cin>>a[i];
        if (a[i] > max){
            max = a[i];
        }
    }
    while (max > 0){
        ++wei;
        max /= 10;
    }
    for (int i = 1;i <= wei;i++){
        for (int j = 1;j <= n;j++){
            f[a[j]/k%10][++f[a[j]/k%10][0]] = a[j];
        }
        int num = 1;
        for (int j = 0;j <= 9;j++){
            for (int p = 1;p <= f[j][0];p++){
                a[num++] = f[j][p];
            }
        }
        k *= 10;
        memset(f, 0, sizeof(f));
    }
    for (int i = 1;i <= n;i++){
        cout<<a[i]<<' ';
    }
    return 0;
}