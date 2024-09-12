#include <iostream>
using namespace std;
int exgcd(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	exgcd(b, a % b, x, y);
	int tx = y;
	int ty = x - a / b * y;
	x = tx;
	y = ty;
}
int main() {
	int a, b, x, y;
	cin >> a >> b;
	exgcd(a, b, x, y);	
	cout << (x % b + b) % b;
	return 0;
}
