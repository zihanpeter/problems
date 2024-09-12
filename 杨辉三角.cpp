#include <iostream>
using namespace std;
const int mod = 1e9;
int n, m, f[1005][1005];
int C(int x, int y){
    for(int i=0;i<=x;i++){
        f[i][0] = 1;
        for(int j=1;j<=i;j++){
            f[i][j] = (f[i-1][j-1]%mod + f[i-1][j]%mod)%mod;
        }
    }
    return f[x][y];
}
int main(){
    cin>>n>>m;
    cout<<C(n, m);
    return 0;
}