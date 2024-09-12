#include <iostream>
using namespace std;
int n, v;
int w[31], c[31], p[31];
int f[201];
int main(){
    cin>>v>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>c[i]>>p[i];
    }
    for(int i=1;i<=n;i++){
        if(p[i] == 0){//完全背包
            for(int j=1;j<=v;j++){
                if(j >= w[i]){
                    f[j] = max(f[j], f[j-w[i]]+c[i]);
                }
            }
        }else if(p[i] == 1){//01背包
            for(int j=v;j>=1;j--){
                if(j >= w[i]){
                    f[j] = max(f[j], f[j-w[i]]+c[i]);
                }
            }
        }else{//多重背包
            for(int j=v;j>=0;j--){
                for(int k=1;k<=p[i];k++){
                    if(j >= k*w[i]){
                        f[j] = max(f[j], f[j-k*w[i]]+k*c[i]);
                    }else{
                        break;
                    }
                }
            }
        }
    }
    cout<<f[v];
    return 0;
}