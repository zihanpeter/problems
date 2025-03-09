#include<iostream>
using namespace std;
#define ac() (p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
char *p1,*p2,buf[100000];
inline int read(){
    int x=0,f=1;
    char ch=ac();
    while(!isdigit(ch)){
        if(ch=='-')f=-1;
        ch=ac();
    }
    while(isdigit(ch))x=x*10+ch-48,ch=ac();
    return x*f;
}
int T,n,m;
const int inf=-0x3f3f3f3f,N=2e5+5;
int a[N],maxn[N];
signed main(){
    freopen("sample.in","r",stdin);
    freopen("std.out","w",stdout);
    T=read();
    while(T--){
        int n=read(),h=0,maxx=0;
        maxn[n+1]=0;
        for(int i=1;i<=n;++i)a[i]=read();
        for(int i=n;i>=1;--i)maxn[i]=max(a[i],maxn[i+1]);
        for(int i=1;i<=n;++i){
            if(maxn[i]==a[i]){
                if(maxx>=maxn[i+1]){
                    for(int j=i;j>h+1;j--)swap(a[j],a[j-1]);
                    break;
                }
                h=i;
                maxx=0;
            }
            else maxx=max(maxx,a[i]);
        }
        for(int i=n;i>=1;i--)maxn[i]=max(maxn[i+1],a[i]);
        for(int i=1;i<=n;i++)if(a[i]==maxn[i])cout<<a[i]<<" ";
        cout<<"\n";
    }
}