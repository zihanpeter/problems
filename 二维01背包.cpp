#include <iostream>
using namespace std;
int c[51], w[51], x[51];
int f[51][401][401];
int n, p, q;
int main(){
    cin>>p>>q;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>x[i]>>c[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=p;j++){
            for(int k=1;k<=q;k++){
                if(j>=w[i] && k>=x[i]){
                    f[i][j][k] = max(f[i-1][j][k], c[i]+f[i-1][j-w[i]][k-x[i]]);
                }else{
                    f[i][j][k] = f[i-1][j][k];
                }
            }
        }
    }
    cout<<f[n][p][q];
    return 0;
}
//¹ö¶¯Êý×é
/*
#include <iostream>
using namespace std;
int c[51], w[51], x[51];
int f[401][401];
int n, p, q;
int main(){
    cin>>p>>q;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>x[i]>>c[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=p;j>=1;j--){
            for(int k=q;k>=1;k--){
                if(j>=w[i] && k>=x[i]){
                    f[j][k] = max(f[j][k], c[i]+f[j-w[i]][k-x[i]]);
                }
            }
        }
    }
    cout<<f[p][q];
    return 0;
}
*/