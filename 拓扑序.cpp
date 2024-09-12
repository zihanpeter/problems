#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector<int> g[10005];
int rudu[10005], n, ti[10005], f[10005];//入度，时间，时间和
queue<int> q;
int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        int duoyu;
        scanf("%d%d", &duoyu, &ti[i]);
        while(true){
            int e;
            scanf("%d", &e);
            if(e == 0) break;
            g[e].push_back(i);//邻接表存储图，同时统计入度
            rudu[i]++;
        }
    }
    for(int i=1;i<=n;i++){
        if(rudu[i] == 0){
            q.push(i);
            f[i] = ti[i];
        }
    }
    while(!q.empty()){//类似广搜，同步出队，出队同时要将邻居的入度-1
        int y = q.front();
        q.pop();
        for(int i=0;i<g[y].size();i++){
            rudu[g[y][i]]--;
            f[g[y][i]] = max(f[g[y][i]], f[y]+ti[g[y][i]]);//当前任务时间+前驱任务时间，是否更新
            if(rudu[g[y][i]]==0) q.push(g[y][i]);//新产生入读为0的节点，入队
        }
    }
    int maxf = -0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        maxf = max(maxf, f[i]);
    }
    printf("%d", maxf);
	return 0;
}

