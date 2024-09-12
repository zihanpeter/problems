//Kruskal
#include <cstdio>
#include <algorithm>
using namespace std;
struct node{
    int u, v, w;
}ns[300005];
long long ans;
int f[200005], n, m;
bool cmp(node a, node b){
    return a.w < b.w;
}
int find(int x){
    if(f[x] == x) return x;
    return f[x] = find(f[x]);
}
void merge(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx != fy) f[fx] = fy;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++){
        f[i] = i;
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d%d", &ns[i].u, &ns[i].v, &ns[i].w);
    }
    sort(ns+1, ns+m+1, cmp);
    int cnt=0;
    for(int i=1;i<=m;i++){
        if(find(ns[i].u) == find(ns[i].v)) continue;
        if(cnt == n-1) break;
        merge(ns[i].u, ns[i].v);
        ans += ns[i].w;
        cnt++;
    }
    if(cnt != n-1) printf("orz");
    else printf("%lld", ans);
    return 0;
}
//Prim 邻接矩阵
#include <iostream>
using namespace std;
const int INF=1e9;//无穷大
bool intree[100005];//表达点是否在生成树中
int dis[100005], n, m;//表达点到生成树的最小距离
long long ans;
int g[1005][1005];
void init(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j){
                g[i][j] = 0;
            }else{
                g[i][j] = INF;
            }
        }
    }
    for(int i=0;i<=n;i++){
        dis[i] = INF;
        intree[i] = false;
    }
    dis[1] = 0;//默认1是生成树的起点
}
int main(){
    scanf("%d%d", &n, &m);
    init();
    for(int i=1;i<=m;i++){//边的输入 矩阵存储图
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        g[x][y] = z;
        g[y][x] = z;
    }
    for(int i=1;i<=n;i++){//将n个点加入到生成树中
        int idx = 0;//默认0为距离生成树最近的点
        for(int j=1;j<=n;j++){
            if(intree[j]==false && dis[idx]>dis[j]){//寻找不在生成树内，距生成树最近的点
                idx = j;
            }
        }
        ans += dis[idx];
		intree[idx] = true;//将idx并入生成树，总距离更新+标记
		for(int k=1;k<=n;k++){//更新邻居的距离
			if(intree[k] == false){
				dis[k] = min(dis[k], g[k][idx]);
			}
		} 
    }
    printf("%lld", ans);
    return 0;
}
//Prim vector
#include <iostream>
#include <vector>
using namespace std;
const int INF=1e9;//无穷大
bool intree[100005];//表达点是否在生成树中
int dis[100005], n, m;//表达点到生成树的最小距离
long long ans;
struct node{
    int id, w;
};
vector<node> g[10005];
void init(){
    for(int i=0;i<=n;i++){
        dis[i] = INF;
        intree[i] = false;
    }
    dis[1] = 0;//默认1是生成树的起点
}
int main(){
    scanf("%d%d", &n, &m);
    init();
    for(int i=1;i<=m;i++){//边的输入 矩阵存储图
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        g[x].push_back(node{y, z});
        g[y].push_back(node{x, z});
    }
    for(int i=1;i<=n;i++){//将n个点加入到生成树中
        int idx = 0;//默认0为距离生成树最近的点
        for(int j=1;j<=n;j++){
            if(intree[j]==false && dis[idx]>dis[j]){//寻找不在生成树内，距生成树最近的点
                idx = j;
            }
        }
        ans += dis[idx];
		intree[idx] = true;//将idx并入生成树，总距离更新+标记
		for(int k=0;k<g[idx].size();k++){//更新邻居的距离
			if(intree[g[idx][k].id] == false){
				dis[g[idx][k].id] = min(dis[g[idx][k].id], g[idx][k].w);
			}
		} 
    }
    printf("%lld", ans);
    return 0;
}