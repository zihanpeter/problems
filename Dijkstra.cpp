#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e9;
int n, m;
struct node{
	int id;
	long long w;
};
vector<node> g[100005];
bool operator < (node x, node y){
	return x.w > y.w;
} 
priority_queue<node> q;
long long ans[100005]; 
bool vis[100005];
int u, v;
long long w;
int main(){
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++){
		ans[i] = INF;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld", &u, &v, &w);
		g[u].push_back(node{v, w});
	}
	q.push({1, 0});//�Լ����Լ������? �㷨�����? 
	while(!q.empty()){
		v = q.top().id;
		w = q.top().w;
		q.pop();
		if(vis[v] == true) continue;//��ϴ������������·��
		vis[v] = true;//���? 
		ans[v] = w;//��¼·������ 
		for(int i=0;i<g[v].size();i++){//�����ھ� 
			node k = g[v][i];
			if(vis[k.id] == false){//���û�г��ӹ�? 
				q.push(node{k.id, k.w+w});//���? 
			}
		}
	} 
	for(int i=1;i<=n;i++){
		if(ans[i] == INF) printf("inf ");
		else printf("%lld ", ans[i]);
	}
	return 0;
} 
