#include <iostream>
using namespace std;
const int N = 5e5 + 5;
int cnt, nxt[N << 1], head[N], to[N << 1], a[N];
void add(int u, int v) {
    nxt[head[u]] = ++cnt; head[u] = cnt; to[cnt] = v;
}
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &u, &v);
        add(u, v);
    }
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    
    return 0;
}

/*


>manage vendor libraries


subsystems
create a new class/cmd
>subsystem







*/