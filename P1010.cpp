#include <iostream>
using namespace std;
void f(int x) {
    if (x <= 1) {
        if (x == 0) printf("0");
        return;
    }
    for (int i = 15; ~i; --i) 
        if (1 << i <= x) {
            printf("2");
            if (i ^ 1) printf("(");
            f(i);
            if (i ^ 1) printf(")");
            x -= 1 << i;
            if (x) printf("+");
        }
}
int main() {
    int n;
    scanf("%d", &n);
    f(n);
    return 0;
}