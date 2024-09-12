#include <iostream>
using namespace std;
int f[1001], w[1001], c[1001];
int t, m;
int main(){
    cin>>t>>m;
    for(int i=1;i<=m;i++){
        cin>>w[i]>>c[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=t;j++){
            if(j >= w[i]){
                f[j] = max(f[j], f[j-w[i]]+c[i]);
            }
        }
    }
    cout<<f[t];
    return 0;
}
//¶þÎ¬Êý×é°æ
int main(){
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>c[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j >= w[i]){
                f[i][j] = max(f[i-1][j], c[i]+f[i-w[i]]);
            }else{
                f[i][j] = f[i-1][j];
            }
        }
    }
}

