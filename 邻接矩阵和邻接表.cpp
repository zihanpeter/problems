//ʯ��������O(n), ����O(n^n), Floyed O(n^3);

//��g[x][y] = 1;��ʾx��y������
//ͬ��g[x][y] = 0;���ʾx��y������
//����ͼ������ͼ����Ȩͼ����Ȩͼ
//�ڽӾ���
#include<iostream>
using namespace std;
int g[10][10]= {
	{0},
	{0, 0, 1, 0, 0, 1},
	{0, 1, 0, 1, 1, 1},
	{0, 0, 1, 0, 1, 0},
	{0, 0, 1, 1, 0, 1},
	{0, 1, 1, 0, 1, 0},
}; // ����1����ͨ�У�����0����ͨ��
int main() {
	for(int i=1; i<=5; i++) { // ȷ��һ��λ��
		cout<<i<<": ";
		for(int j=1; j<=5; j++) // ���������ӵĵ�
			if(g[i][j]==1) {
				cout<<j<<' ';
			}
		cout<<endl;
	}
	return 0;
}

/*
һ��ʵ��Ŀ��
����n�����㡢m���ߵ������Ȩͼ������ÿ���������ӵıߵ����ֵ��Ȩ�����ֵ����

���ĳ����û�����ӣ������-inf��

ע�⣺Ȩ�п����Ǹ�����

�����ʽ��

��һ��n��m����ʾ�������ͱ���
������m�бߣ�ÿ����������ʾһ���ߣ�x, y����Ȩz
�����ʽ��

n��������ʾ��Ӧ�������ӵ����Ȩ
���ĳ������û�����ӣ���õ����"-inf"
��������1��

5 6
1 2 -2
1 3 -5
1 4 -4
2 3 -6
2 4 -1
3 4 2
���������

-2 -1 2 2 -inf
���ݷ�Χ��1<=n<=1000
*/
//�ڽӾ�������
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
//�ڽӱ�����
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

//�ڽӾ������
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

//�ڽӱ����
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

//ͼ�����Ȩֵ�� + ����·������
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

//���ѱ����������·����
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,m,sx,fx,ans,d[1005];// d[x]=2 ,x��������̾���Ϊ2
bool vis[1005];
vector<int> g[1005];
void bfs() {
	queue<int> q;
	q.push(sx);//�����еĵ���δ�߹��ĵ㣬ֻ�Ƿ���û���߹�
	vis[sx]=true;//��Ƕ����еĵ�
	d[sx]=0;
	while(!q.empty()) {
		int x=q.front();//x��ʾ��ǰ�ĵ�
		cout<<x<<' ';
		q.pop();//���ӵĵ��ʾ�߹��ĵ�
		if(x==fx) {
			return ;
		}
		for(int i=0; i<g[x].size(); i++) {
			int y=g[x][i];
			if(vis[y]==true) continue; //�ж�Ŀ�����û���ڶ�����
			vis[y]=true;
			d[y]=d[x]+1;
			q.push(y); //dfs ���߹� dfs(y) ��bfs ��� �� q.push(y);
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


//queue�Թ����·
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
			int dy=e.y+cy[i];//dx,dy ����� x,y ���Ե��ĸ�����
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

//floyd�㷨��
//���·�㷨�����ڽ����Դ���·���кܶ�������յ�
#include<iostream>
using namespace std;
const int N=105;
int d[N][N]; // d[x][y]=z x��y����СȨ
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
	for(int k=1; k<=n; k++) { //k��ʾҪ�����ĵ�
		for(int i=1; i<=n; i++) { //ö�����
			for(int j=1; j<=n; j++) { //ö���յ�
				if( d[i][j] > d[i][k] + d[k][j] )//Ҳ�����жϴ�iֱ�ӵ�j�����Ǿ���k�ٵ���
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
//����һ�������Ȩͼ������Ӹ�������s��������ÿ�������̾��롣
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
struct Edge { //��
	int y, w; // y Ŀ��� , w ����Ŀ����Ȩֵ
};
struct Node { //��
	int y, d; // y ��ʾ��ǰ��λ�� �� d ��ǰλ�þ������Ĵ�С
	//���������
	bool operator < (const Node &n1) const {  // ���ⲿ����һ������Ƚϵ�ֵ
		return d > n1.d; // d �����Ȩֵ , n1.d �ⲿ��Ȩֵ
	}
};
const int inf=0x3f3f3f3f;
const int N=100005;
int n, m, s, d[N];
vector<Edge> g[N];
bool vis[N];
void dijkstra(int v0) {
	//priority_queue<Node, vector<Node>, greater<Node> > q;
	priority_queue<Node> q; //���ȶ��У����������������Ϊ���ȣ������Խ���ڶ����Խǰ��
	memset(d, 0x3f, sizeof(d));
	memset(vis, false, sizeof(vis));
	d[v0]=0;
	q.push((Node) {
		v0,0
	});
	while(!q.empty()) {
		Node n1 = q.top(); // ��ȡ���ף����������ĵ�
		q.pop();
		int x = n1.y;
		if(vis[x]) continue;
		vis[x] = true; //����x�㣬���x��
		for(int j=0; j<g[x].size(); j++) { //��x�������Ե���㣬�����������
			Edge next = g[x][j];
			int y = next.y, w=next.w;
			if(vis[y]) continue;
			if(d[x]+w < d[y]) {
				d[y] = d[x] + w; // ������������
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
// ������ �� �������Ϊ0�ĵ�
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
		if(in[i]==0) //���Ϊ0ֱ�ӽ���
			q.push(i);

	while(!q.empty()) {
		int x = q.front();
		q.pop();
		ans.push_back(x); // ���
		for(int i=0; i<g[x].size(); i++) {
			int y = g[x][i];
			in[y]--;
			if(in[y] == 0)
				q.push(y);
		}
	}
	if(ans.size() != n) {
		cout<<"�л�"<<endl;
		return 0;
	}
	for(int i=0; i<ans.size(); i++)
		cout<<ans[i]<<" ";
	cout<<endl;

	return 0;
}






