//高精度加法
#include <iostream>
#include <string>
using namespace std;
int a[1001], b[1001], c[1001];

int main(){
	string s1, s2;
	cin>>s1>>s2;
	int len1 = s1.length();
	int len2 = s2.length();
	for(int i=len1-1;i>=0;i--){
		a[len1-i] = s1[i]-'0';
	}
	for(int i=len2-1;i>=0;i--){
		b[len2-i] = s2[i]-'0';
	}
	int len3 = max(len1, len2);
	for(int i=1;i<=len3;i++){
		c[i] += a[i]+b[i];
		if(c[i]>=10) ++c[i+1];
		c[i] %= 10;
	}
	if(c[len3+1] > 0){
		++len3;
	}
	for(int i=len3;i>=1;i--){
		cout<<c[i];
	}
	return 0;
} 
//高精度减法
#include <iostream>
using namespace std;
string s1, s2;
int a[1005], b[1005], c[1005];
int main(){
	cin>>s1>>s2;
	if(s1 == s2){
		cout<<0;
		return 0;
	}
	if(s2.size() > s1.size()){
		swap(s1, s2);
		cout<<'-';
	}
	int len1 = s1.length();
	int len2 = s2.length();
	for(int i=len1-1;i>=0;i--){
		a[len1-i] = s1[i]-'0';
	}
	for(int i=len2-1;i>=0;i--){
		b[len2-i] = s2[i]-'0';
	}
	int len3 = max(len1, len2);
	for(int i=1;i<=len3;i++){
		c[i] = a[i]-b[i];
		if(c[i] < 0){
			c[i] += 10;
			a[i+1]--; 
		}
	}
	bool flag = false;
	for(int i=len3;i>=1;i--){
		if(flag == false && c[i] != 0) flag = true;
		if(flag == true) cout<<c[i];
	}
	return 0;
} 
//高精度乘法 高精度乘高精度
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main(){
	//准备工作
	int a[1001], b[1001], c[100000];
	int lena, lenb, lenc;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	string s = "";
	cin>>s;
	int temp = 1;
	for(int i=s.length()-1;i>=0;i--){
		a[temp] = s[i] - '0';
		++temp;
	}
	lena = s.length();
	temp = 1;
	cin>>s;
	for(int i=s.length()-1;i>=0;i--){
		b[temp] = s[i] - '0';
		++temp;
	}
	lenb = s.length();
	//乘法部分
	for(int i=1;i<=lena;i++){
		for(int j=1;j<=lenb;j++){
			c[i+j-1] += a[i] * b[j];
		}
	}
	lenc = lena + lenb;
	for(int i=1;i<=lenc;i++){
		c[i+1] += c[i]/10;
		c[i] %= 10;
	}
	while(lenc > 1 && c[lenc] == 0){
		--lenc;
	}
	for(int i=lenc;i>=1;i--){
		cout<<c[i];
	}
	return 0;
} 
//高精度乘法 高精乘低精
//题目背景
/*
	求n!中某个数码出现的次数。 
	输入一个正整数n(≤1000)和数码a。 
*/
#include <iostream>
using namespace std;
int main(){
	int len = 1;
	int a[100001] = {0};
	a[1] = 1;
	int n;
	int info;
	cin>>n>>info;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=len;j++){
			a[j] = a[j]*i;
		}
		for(int j=1;j<=len;j++){
			a[j+1] += a[j]/10;
			a[j] %= 10;
			if(j==len && a[j+1]>0){
				++len;
			}
		}
	}
	int ans = 0;
	for(int i=1;i<=len;i++){
		if(a[i] == info){
			++ans;
		}
	}
	cout<<ans;
	return 0;
}  

//Summer Camp
#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 1e6;
const int BASE = 10;
char s[MAX];
int a1[MAX], a2[MAX], a3[MAX];
void f(int a[], char s[]){
	a[0] = strlen(s);
	for(int i=1, j=a[0]-1;i<=a[0];i++, j--){
		a[i] = s[j] - '0';
	}
	//或
	// for(int i=1;i<=a[0];i++){
	// 	a[i] = s[a[0]-i] - '0';
	// }
}
void print(int a[]){
	for(int i=a[0];i;i--){
		printf("%d", a[i]);
	}
	printf("\n");
}
void big_add(int *a, int *b, int *c){
	c[0] = max(a[0], b[0]);
	for(int i=1;i<=c[0];i++){
		c[i] = a[i] + b[i];
	}
	for(int i=1;i<=c[0];i++){
		c[i+1] += c[i] / BASE;
		c[i] %= BASE;
	}
	if(c[c[0]+1]) c[0]++;
}
void big_minus(int *a, int *b, int *c){
	c[0] = a[0];
	for(int i=1;i<=c[0];i++){
		c[i] = a[i] - b[i];
	}
	for(int i=1;i<=c[0];i++){
		if(c[i] < 0){
			c[i] += BASE;
			c[i+1]--;
		}
	}
	while(c[0]>1 && !c[c[0]]) c[0]--;
}
void big_muti(int *a, int *b, int *c){
	for(int i=1;i<=a[0];i++){
		for(int j=1;j<=b[0];j++){
			c[i+j-1] += a[i]*b[j];
		}
	}
	c[0] = a[0]+b[0];
	for(int i=1;i<=c[0];i++){
		c[i+1] += c[i]/BASE;
		c[i] %= BASE;
	}
	while(c[0]>1 && !c[c[0]]) c[0]--;
}
int big_divide(int a[], int b, int c[]){
	int r=0;
	for(int i=a[0];i;i--){
		r = r*BASE+a[i];
		c[i] = r/b;
		r %= b;
	}
	c[0] = a[0];
	while(c[0] > 1 && !c[c[0]]) c[0]--;
	return r;
}
int main(){
	scanf("%s", s);
	f(a1, s);
	// scanf("%s", s);
	// f(a2, s);
	int c;
	scanf("%d", &c);
	// //a3 = a1 + a2
	// big_add(a1, a2, a3);
	// print(a3);
	// //a3 = a1 - a2
	// big_minus(a1, a2, a3);
	// print(a3);
	// //a3 = a1 * a2
	// big_muti(a1, a2, a3);
	// print(a3);
	//a3 = a1 / c ...... b
	int b = big_divide(a1, c, a3);
	printf("%d\n", b);
	print(a3);
	return 0;
}