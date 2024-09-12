/*//Êı×éÄ£ÄâÁ´±íÊµÀı 
#include <iostream>
using namespace std;
const int MAXN = 1e4+5;
struct Node{
	int prev;
	int value;
	int next;
};
Node a[MAXN];
int main(){
	int n = 5;
	for(int i=1;i<=n;i++){
		a[i].value = i*100;
	}
	//´æ´¢µÄË³Ğò£º100 200 300 400 500
	//Âß¼­µÄË³Ğò£º100 500 300 400 200
	a[0].next = 1;
	a[1].next = 5;
	a[2].next = 0;
	a[3].next = 4;
	a[4].next = 2;
	a[5].next = 3;
	a[0].prev = 2;
	a[1].prev = 0;
	a[2].prev = 4;
	a[3].prev = 5;
	a[4].prev = 3;
	a[5].prev = 1;
	for(int p=a[0].next;p;p=a[p].next){
		cout<<a[p].value<<endl;
	}
	for(int p=a[0].prev;p;p=a[p].prev){
		cout<<a[p].value<<endl;
	}
	cout<<"----------------"<<endl;
	//´æ´¢µÄË³Ğò£º100 200 300 400 500 230
	//Âß¼­µÄË³Ğò£º100 500 230 300 400 200
	a[6].value = 230;
	a[6].next = 3;
	a[5].next = 6;
	a[6].prev = 5;
	a[3].prev = 6;
	for(int p=a[0].next;p;p=a[p].next){
		cout<<a[p].value<<endl;
	}
	for(int p=a[0].prev;p;p=a[p].prev){
		cout<<a[p].value<<endl;
	}
	//´æ´¢µÄË³Ğò£º100 200 300 400 500 230
	//Âß¼­µÄË³Ğò£º100 500 230 300 200
	a[3].next = 2;
	a[2].prev = 3;
	cout<<"----------------"<<endl;
	for(int p=a[0].next;p;p=a[p].next){
		cout<<a[p].value<<endl;
	}
	for(int p=a[0].prev;p;p=a[p].prev){
		cout<<a[p].value<<endl;
	}
	return 0;
}

#include <iostream>
using namespace std;
struct node{
	int pre;
	int data;
	int next;
}a[200005];
int n;
int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%d", &a[i].data);
		a[i].next = i+1;
		a[i].pre = i-1;
	}
	a[0].pre = n;
	a[0].next = 1;
	a[0].data = -1;
	a[n].next = 0;
	for(int i=1;i<=n;i++){
		int t;
		scanf("%d", &t);
		printf("%d ", a[a[t].pre].data);
		printf("%d\n", a[a[t].next].data);
		a[a[t].pre].next = a[t].next;
		a[a[t].next].pre = a[t].pre;
	}
	return 0;
}
*/

