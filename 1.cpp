#include <iostream>
using namespace std;

bool check(int x) {
    for (int i = 2; i * i <= x; ++i) 
        if (!(x % i)) return false;
    return true;
}

int main() {
	int a, b;
	b = a / 3 + !(a % 3);
	cout << b << endl;
    return 0;
}
