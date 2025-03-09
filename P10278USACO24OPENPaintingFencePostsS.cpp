#include <iostream>
using namespace std;
const int N = 2e5 + 5;

int n, p;
struct node {
    int x1, y1, x2, y2;
} col[N], cow[N];

int main() {
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= p; ++i) scanf("%d%d", &col[i].x1, &col[i].y1);
    for (int i = 1; i <= n; ++i) scanf("%d%d%d%d", &cow[i].x1, &cow[i].y1, &cow[i].x2, &cow[i].y2);
    
    return 0;
}