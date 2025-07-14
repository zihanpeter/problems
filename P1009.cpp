#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e2 + 5;
int a[N], s[N];

void mult(int x) {
    for (int i = 1; i <= a[0]; ++i) a[i] *= x;
    for (int i = 1; i <= a[0]; ++i) 
        if (a[i] > 9) {
            a[i + 1] += a[i] / 10;
            a[0] = max(a[0], i + 1);
            a[i] = a[i] % 10;
        }   
}

void add() {
    s[0] = max(s[0], a[0]);
    for (int i = 1; i <= s[0]; ++i) {
        s[i] += a[i];
        if (s[i] > 9) {
            ++s[i + 1];
            s[0] = max(s[0], i + 1);
            s[i] = s[i] % 10;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        memset(a, 0, sizeof(a));
        a[0] = a[1] = 1;
        for (int j = 2; j <= i; ++j) mult(j);
        add();
    }
    for (int i = s[0]; i >= 1; --i) printf("%d", s[i]);
    return 0;
}