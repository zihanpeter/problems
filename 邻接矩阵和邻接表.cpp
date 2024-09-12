//石斧：广搜O(n), 深搜O(n^n), Floyed O(n^3);

//用g[x][y] = 1;表示x和y有连接
//同理g[x][y] = 0;则表示x和y无连接
//有向图，无向图，带权图，无权图
//邻接矩阵
#include<iostream>
using namespace std;
int g[10][10]= {
	{0},
	{0, 0, 1, 0, 0, 1},
	{0, 1, 0, 1, 1, 1},
	{0, 0, 1, 0, 1, 0},
	{0, 0, 1, 1, 0, 1},
	{0, 1, 1, 0, 1, 0},
}; // 等于1可以通行，等于0不能通行
int main() {
	for(int i=1; i<=5; i++) { // 确定一个位置
		cout<<i<<": ";
		for(int j=1; j<=5; j++) // 跟自身连接的点
			if(g[i][j]==1) {
				cout<<j<<' ';
			}
		cout<<endl;
	}
	return 0;
}

/*
一、实验目标
给出n个顶点、m条边的无向加权图，计算每个顶点连接的边的最大值（权的最大值）。

如果某顶点没有连接，则输出-inf。

注意：权有可能是负数。

输入格式：

第一行n、m，表示顶点数和边数
接下来m行边，每行三个数表示一条边（x, y）与权z
输出格式：

n个数，表示对应顶点连接的最大权
如果某个顶点没有连接，则该点输出"-inf"
输入样例1：

5 6
1 2 -2
1 3 -5
1 4 -4
2 3 -6
2 4 -1
3 4 2
输出样例：

-2 -1 2 2 -inf
数据范围：1<=n<=1000
*/
//邻接矩阵做法
#include <iostream>
#include <vector>
using namespace std;
int g[1001][1001];
int n, m;
int main() {
	cin>>n>>m;
	for(int i=1; i<=m; i++) {
		int x, y, z;
		cin>>x>>y>>z;
		g[x][y] = z;
		g[y][x] = z;
	}
	for(int i=1; i<=n; i++) {
		int ans = -0x3f3f3f3f;
		bool flag = false;
		for(int j=1; j<=n; j++) {
			if(g[i][j]!=0) {
				ans = max(g[i][j], ans);
				flag = true;
			}
		}
		if(flag==false) {
			cout<<"-inf"<<' ';
		} else {
			cout<<ans<<' ';
		}
	}
	return 0;
}
//邻接表做法
#include <iostream>
#include <vector>
using namespace std;
struct edge {
	int y, z;
};
vector<edge> g[1001];
int main() {
	int n, m;
	cin>>n>>m;
	for(int i=1; i<=m; i++) {
		int x, y, z;
		cin>>x>>y>>z;
		g[x].push_back({y,z});
		g[y].push_back({x,z});
	}
	for(int i=1; i<=n; i++) {
		int ans = -0x3f3f3f3f;
		for(int j=0; j<g[i].size(); j++) {
			int y = g[i][j].y, z = g[i][j].z;
			ans = max(ans, z);
		}
		if(g[i].size()==0) {
			cout<<"-inf"<<' ';
		} else {
			cout<<ans<<' ';
		}
	}
	return 0;
}

//邻接矩阵遍历
#include <iostream>
#include <vector>
using namespace std;
char s[1001];
int g[105][105];
bool vis[105];
int n, m;
void dfs(int x) {
	cout<<s[x];
	for(int i=1; i<=n; i++) {
		if(vis[i]==true) {
			continue;
		}
		if(g[x][i]==1) {
			vis[i] = true;
			dfs(i);
		}
	}
}
int main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>s[i];
	}
	for(int i=1; i<=m; i++) {
		int x, y;
		cin>>x>>y;
		g[x][y] = 1;
	}
	vis[1] = true;
	dfs(1);
}

//邻接表遍历
#include <iostream>
#include <vector>
using namespace std;
char s[105];
vector<int> g[105];
bool vis[105];
int n, m;
void dfs(int x) {
	cout<<s[x];
	for(int i=0; i<g[x].size(); i++) {
		int y = g[x][i];
		if(vis[y]==true) {
			continue;
		}
		vis[y] = true;
		dfs(y);
	}
}
int main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>s[i];
	}
	for(int i=1; i<=m; i++) {
		int x, y;
		cin>>x>>y;
		g[x].push_back(y);
	}
	vis[1] = true;
	dfs(1);
}

//图的最大权值和 + 具体路径代码
#include <iostream>
#include <vector>
using namespace std;
int n, m, sx, fx;
struct node {
	int x, info;
};
vector<node> g[1000];
bool vis[1000];
int path[1000];
int ansPath[1000];
int ans;
int ansLen;
void dfs(int x, int sum, int cnt) {
	path[cnt] = x;
	if(x == fx) {
		if(sum > ans) {
			ansLen = cnt;
			ans = sum;
			for(int i=1; i<=cnt; i++) {
				ansPath[i] = path[i];
			}
		}
		return;
	}
	for(int i=0; i<g[x].size(); i++) {
		int y = g[x][i].x;
		if(vis[y] == true) continue;
		vis[y] = true;
		dfs(y, sum+g[x][i].info, cnt+1);
		vis[y] = false;
	}
}
int main() {
	cin>>n>>m>>sx>>fx;
	for(int i=1; i<=m; i++) {
		int x, y, z;
		cin>>x>>y>>z;
		g[x].push_back({y, z});
		g[y].push_back({x, z});
	}
	vis[sx] = true;
	dfs(sx, 0, 1);
	if(ans == 0) {
		cout<<0;
	} else {
		cout<<ans<<endl;
		for(int i=1; i<=ansLen; i++) {
			cout<<ansPath[i]<<' ';
		}
	}
	return 0;
}

//广搜遍历（求最短路径）
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,m,sx,fx,ans,d[1005];// d[x]=2 ,x离起点的最短距离为2
bool vis[1005];
vector<int> g[1005];
void bfs() {
	queue<int> q;
	q.push(sx);//队伍中的点是未走过的点，只是发现没有走过
	vis[sx]=true;//标记队伍中的点
	d[sx]=0;
	while(!q.empty()) {
		int x=q.front();//x表示当前的点
		cout<<x<<' ';
		q.pop();//出队的点表示走过的点
		if(x==fx) {
			return ;
		}
		for(int i=0; i<g[x].size(); i++) {
			int y=g[x][i];
			if(vis[y]==true) continue; //判断目标点有没有在队伍中
			vis[y]=true;
			d[y]=d[x]+1;
			q.push(y); //dfs ，走过 dfs(y) ，bfs 入队 ， q.push(y);
		}
	}
}
int main() {
	cin>>n>>m>>sx>>fx;
	for(int i=1; i<=m; i++) {
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	bfs();
	cout<<d[fx];
	return 0;
}


//queue迷宫最短路
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N=705;
int n,m,fx,fy,sx,sy,k;
struct node {
	int x,y;
};
bool vis[N][N];
int d[N][N];
int cx[]= {-1,0,1,0};
int cy[]= {0,1,0,-1};
void bfs() {
	queue<node> q;
	q.push({sx,sy});
	vis[sx][sy]=true;
	d[sx][sy]=0;
	while(!q.empty()) {
		node e=q.front();
		q.pop();
		for(int i=0; i<4; i++) {
			int dx=e.x+cx[i];
			int dy=e.y+cy[i];//dx,dy 相对于 x,y 而言的四个方向
			if(vis[dx][dy]==true) continue;
			if(dx<1||dx>n||dy<1||dy>m) continue;
			vis[dx][dy]=true;
			d[dx][dy]=d[e.x][e.y]+1;
			q.push({dx,dy});
		}
	}
}
int main() {
	cin>>n>>m>>k;
	cin>>sx>>sy>>fx>>fy;
	for(int i=1; i<=k; i++) {
		int x,y;
		cin>>x>>y;
		vis[x][y]=true;
	}
	bfs();
	if(d[fx][fy]==0) cout<<-1;
	else cout<<d[fx][fy];
	return 0;
}

//floyd算法，
//最短路算法：用于解决多源最短路，有很多的起点和终点
#include<iostream>
using namespace std;
const int N=105;
int d[N][N]; // d[x][y]=z x到y的最小权
int main() {
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			d[i][j]=0x3f3f3f3f;

	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		int x,y,z;
		cin>>x>>y>>z;
		d[x][y]=z;
		d[y][x]=z;
	}
	for(int k=1; k<=n; k++) { //k表示要经过的点
		for(int i=1; i<=n; i++) { //枚举起点
			for(int j=1; j<=n; j++) { //枚举终点
				if( d[i][j] > d[i][k] + d[k][j] )//也就是判断从i直接到j近还是经过k再到近
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}

	for(int i=1; i<=k; i++) {
		int x,y;
		cin>>x>>y;
		cout<<d[x][y]<<endl;
	}
	return 0;
}

//dijkstra
//给定一个有向加权图，计算从给定顶点s出发，到每个点的最短距离。
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
struct Edge { //边
	int y, w; // y 目标点 , w 到达目标点的权值
};
struct Node { //点
	int y, d; // y 表示当前的位置 ， d 当前位置距离起点的大小
	//重载运算符
	bool operator < (const Node &n1) const {  // 在外部接受一个参与比较的值
		return d > n1.d; // d 自身的权值 , n1.d 外部的权值
	}
};
const int inf=0x3f3f3f3f;
const int N=100005;
int n, m, s, d[N];
vector<Edge> g[N];
bool vis[N];
void dijkstra(int v0) {
	//priority_queue<Node, vector<Node>, greater<Node> > q;
	priority_queue<Node> q; //优先队列，以离起点距离最近的为优先，离起点越近在队伍就越前面
	memset(d, 0x3f, sizeof(d));
	memset(vis, false, sizeof(vis));
	d[v0]=0;
	q.push((Node) {
		v0,0
	});
	while(!q.empty()) {
		Node n1 = q.top(); // 提取队首，离起点最近的点
		q.pop();
		int x = n1.y;
		if(vis[x]) continue;
		vis[x] = true; //访问x点，标记x点
		for(int j=0; j<g[x].size(); j++) { //从x出发可以到达点，计算最近距离
			Edge next = g[x][j];
			int y = next.y, w=next.w;
			if(vis[y]) continue;
			if(d[x]+w < d[y]) {
				d[y] = d[x] + w; // 计算离起点距离
				q.push((Node) {
					y, d[y]
				});
			}
		}
	}
}

int main() {
	cin>>n>>m>>s;
	for(int i=1; i<=m; i++) {
		int x,y,w;
		scanf("%d%d%d", &x, &y, &w);
		g[x].push_back((Edge) {
			y, w
		});
	}
	dijkstra(s);
	for(int i=1; i<=n; i++)
		printf("%d ", (d[i]==inf?-1:d[i]));
	return 0;
}

/*
// 拓扑序 ， 访问入度为0的点
#include <iostream>
#include <vector>
using namespace std;

const int N=1e5;
int n, m, ans[N], last , rd[N];
vector<int> g[N];
bool vis[N];

void dfs(int x) {
  vis[x]=true;
  cout<<x<<' ';
  for(int i=0;i<g[x].size();i++){
    int y=g[x][i];
    rd[y]--;
    if(rd[y]==0)
      dfs(y);
  }
}

int main() {
  cin>>n>>m;
  for(int i=1; i<=m; i++) {
    int x, y;
    cin>>x>>y;
    g[x].push_back(y);
    rd[y]++;
  }
  for(int i=1;i<=n;i++){
    if(rd[i]==0 && vis[i]==false)
      dfs(i);
  }
  return 0;
}*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N=1e5;
int n, m, in[N];
vector<int> g[N], ans;
queue<int> q;

int main() {
	cin>>n>>m;
	for(int i=1; i<=m; i++) {
		int x, y;
		cin>>x>>y;
		g[x].push_back(y);
		in[y]++;
	}

	for(int i=1; i<=n; i++)
		if(in[i]==0) //入度为0直接进入
			q.push(i);

	while(!q.empty()) {
		int x = q.front();
		q.pop();
		ans.push_back(x); // 求答案
		for(int i=0; i<g[x].size(); i++) {
			int y = g[x][i];
			in[y]--;
			if(in[y] == 0)
				q.push(y);
		}
	}
	if(ans.size() != n) {
		cout<<"有环"<<endl;
		return 0;
	}
	for(int i=0; i<ans.size(); i++)
		cout<<ans[i]<<" ";
	cout<<endl;

	return 0;
}






