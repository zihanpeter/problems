#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
long long n, h, r;
long long x[2005], y[2005], z[2005];
bool vis[2005];
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n>>h>>r;
		vector<int> g[2005];
		for(int i=1;i<=n;i++){
			cin>>x[i]>>y[i]>>z[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i == j) continue;
				if(j >= i) continue;
				long long dist;
				dist = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]);
				if(dist <= (4*r*r)){
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
			if(z[i] <= r){
				g[i].push_back(n+5);
				g[n+5].push_back(i);
			}
			if(h-r <= z[i]){
				g[i].push_back(n+10);
				g[n+10].push_back(i);
			}
		}
		bool flag = false;
		memset(vis, 0, sizeof(vis));
		queue<int> q;
		q.push(n+5);
		while(!q.empty()){
			int x;
			x = q.front();
			for(int i=0;i<g[x].size();i++){
				int y;
				y = g[x][i];
				if(vis[y]) continue;
				vis[y] = true;
				q.push(y);
				if(y == (n+10) && flag == false){
					cout<<"Yes"<<endl;
					flag = true;
				}
			}
			q.pop();
		}
		if(flag == false){
			cout<<"No"<<endl;
		}
		
	}
	return 0;
}