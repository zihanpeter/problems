#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (b >= c) c += 24, a += 24;
    if (b <= a && a <= c) printf("No");
    else printf("Yes");
    return 0;
}