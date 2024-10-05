#include <bits/stdc++.h>
using namespace std;
struct stu{
	char name[10];
	int a;
	int b;
	int c;
	int z;
    int f;
}s[1010];
bool cmp(stu a, stu b){
    if (a.z == b.z) return a.f < b.f;
	return a.z > b.z;
}
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1;i <= n;i++){
		scanf("%s", s[i].name);
		scanf("%d %d %d", &s[i].a, &s[i].b, &s[i].c);
		s[i].z = s[i].a + s[i].b + s[i].c;
        s[i].f = i;
	}
	sort(s+1,s+n+1,cmp);
	printf("%s %d %d %d", s[1].name, s[1].a, s[1].b, s[1].c);
	return 0;
} 