#include <iostream>
using namespace std;
const int N = 15;
int a[N], prime[N] = {0, 2, 3, 5, 7, 11, 13};

int main() {
    string s;
    getline(cin, s);
	int mem = 0, num = 1, flag = 0, a1;
    for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '+') {
			a1 = mem;
			mem = 0;
		} else if (s[i] == ',') {
			

    }
    return 0;
}
