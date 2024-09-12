#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<int> g[100005];
set<int> se;
bool prime[1005];
int rudu[100005], f[100005];
int cnt, primes[1005];
int n, a[50005];
int ans;
void initPrime() {
    for (int i = 2; i <= 1000; ++i) {
        if (prime[i]) 
            continue;
        for (int j = 2; i * j <= 1000; ++j) 
            prime[i * j] = true;
    }
    for (int i = 2; i <= 1000; ++i) 
        if (!prime[i]) 
            primes[++cnt] = i;
    return;
}
int dfs(int x, int step) {
    if (f[x]) 
        return f[x];
    f[x] = 1;
    int maxf = 0;
    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i];
        dfs(y, step + 1);
        maxf = max(maxf, f[y]);
    }
    return f[x] += maxf;
}
int main() {
    // freopen("ађСа.in", "r", stdin);
    initPrime();
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        // cout << a[i] << ' ';
    }
    // cout << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= cnt; ++j) {
            if (a[i] % primes[j] == 0) {
                if (primes[j] == a[i] / primes[j]) {
                    break;
                }
                // cout << primes[j] << ' ' << a[i] / primes[j] << endl;
                g[min(primes[j], a[i] / primes[j])].push_back(max(primes[j], a[i] / primes[j]));
                ++rudu[max(primes[j], a[i] / primes[j])];
                se.insert(primes[j]);
                se.insert(a[i] / primes[j]);
                break;
            }
        }
    }
    for (auto it = se.begin(); it != se.end(); ++it) {
        if (rudu[*it] == 0) 
            ans = max(ans, dfs(*it, 1));
    }
    printf("%d", ans - 1);
    return 0;
}