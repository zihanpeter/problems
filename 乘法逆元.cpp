//exgcd
#include <iostream>
using namespace std;
int a, b, c;
void exgcd(int a, int c, int &x, int &y) {
	if(c == 0) {
		//a就是最大公约数，a和c互质才能存在乘法逆元
		x = 1;
		y = 0;
		if(a != 1) {
			cout<<-1;
			exit(0);
		}
	} else {
		exgcd(c, a%c, x, y);
		//回溯，根据迭代关系，递推出x的起始值
		int t = x;
		x = y;
		y = t - (a/c) * y;
	}
}
int main() {
	cin>>a>>c;
	int x, y;//a*x+c*y=gcd(a,c) x就是a的逆元
	exgcd(a, c, x, y);
	cout<<(x+c)%c;//防止x为负数
	return 0;
}
//优化：递推法
// 求1..n里每个数在模p意义下的乘法逆元。
#include <iostream>
using namespace std;
typedef long long ll;
const int N=1e7+5;
int n, p, f[N];
int main() {
	cin>>n>>p;
	f[1] = 1;
	for(int i=2; i<=n; i++)
		f[i] = (1LL*(p-p/i)*f[p%i])%p;
	for(int i=1; i<=n; i++)
		printf("%d ", f[i]);
	printf("\n");
	return 0;
}

/*
//费马小定理求每个数的逆元
#include <iostream>
using namespace std;
typedef long long ll;
int n, p;

int quick_pow(int a, int b) {
  int ans = 1;
  while(b) {
    if(b%2==1) ans = (1LL*ans*a)%p;
    a = (1LL*a*a)%p;
    b /= 2;
  }
  return ans;
}

int main() {
  cin>>n>>p;
  int phi = p-1;
  for(int i=1; i<=n; i++) {
    printf("%d ", quick_pow(i, phi-1));
  }
  cout<<endl;
  return 0;
}

*/
