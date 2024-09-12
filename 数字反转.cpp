#include <iostream>
using namespace std;
int main() {
	int x;
	cin>>x;
	if (x < 0) {
		cout << '-';
		x = -x;
		int ans=0;
		while(x != 0) {
			ans = ans*10 + x%10;
			x /= 10;
		}
		cout<<ans;
	}else {
		int ans=0;
		while(x != 0) {
			ans = ans*10 + x%10;
			x /= 10;
		}
		cout<<ans;
	}
	return 0;
}
