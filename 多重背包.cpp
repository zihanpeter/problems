/*
#include <iostream>
using namespace std;
int n, m, v[505], w[505], s[505], f[6006];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i]>>s[i];//价格(weight)、价值(value)、件数
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            for(int k=1;k<=s[i];k++){
                if(j >= k*v[i]){
                    f[j] = max(f[j], f[j-k*v[i]]+k*w[i]);
                }else{
                    break;
                }
            }
        }
    }
    cout<<f[m];
    return 0;
}
*/





//另一种写法
/*
for(int i=1;i<=n;i++){
    for(int k=1;k<=s[i];k++){
        for(int j=m;j>=0;j--){
            if(j >= v[i]){
                f[j] = max(f[j], f[j-v[i]]+w[i]);
            }
        }
    }
}
*/
#include <iostream>
using namespace std;
int n, m, v[5005], w[5005], f[6006];//每种物品最多按照二进制分组，分成10组， 所以v, w, s扩大十倍
int main(){
    int x, y, z, cnt=1;//cnt表示分组后，物品的种类
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x>>y>>z;//价格，价值，数量
        //二进制分组
        int k=1;
        while(z >= k){//够分就继续
            v[cnt] = k*x;//该分的价格
            w[cnt] = k*y;//改分的价值
            ++cnt;
            z -= k;
            k *= 2;
        }
        if(z != 0){//二进制分组所剩的余数处理
            v[cnt] = z*x;//该分的价格
            w[cnt] = z*y;//改分的价值
            ++cnt;
        }
    }
    for(int i=1;i<cnt;i++){
        for(int j=m;j>=0;j--){
            if(j >= v[i]){
                f[j] = max(f[j], f[j-v[i]]+w[i]);
            }
        }
    }
    cout<<f[m];
    return 0;
}
