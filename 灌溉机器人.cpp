#include <iostream>
using namespace std;
int n, m, dp[105][65][65], dic[1029], num;
char s[105][15];
void init() {
    for (int i = 0; i < (1 << m); ++i) {
        if (((i << 1) & i ) || ((i << 2) & i)) 
            continue;
        dic[++num] = i;
    }
}
int getSum(int x) {
    int sum = 0;
    while (x) {
        if (x % 2) 
            ++sum;
        x >>= 1;
    }
    return sum;
}
bool checkDirt(int row, int x) {
    int k = m;
    while (x) {
        if (x % 2 && s[row][k] == 'H') 
            return false;
        x >>= 1;
        --k;
    }
    return true;
}
int main() {
    // freopen("robot.in", "r", stdin);
    // freopen("robot.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) 
        scanf("%s", s[i] + 1);
    init();
    for (int i = 1; i <= num; ++i) {
        if (!checkDirt(1, dic[i])) 
            continue;
        dp[1][i][0] = getSum(dic[i]);
    }
    for (int i = 1; i <= num; ++i) {
        if (!checkDirt(2, dic[i])) 
            continue;
        for (int j = 1; j <= num; ++j) {
            if (!checkDirt(1, dic[j])) 
                continue;
            if (dic[i] & dic[j])
                continue;
            dp[2][i][j] = dp[1][j][0] + getSum(dic[i]);
        }
    }
    for (int r = 3; r <= n; ++r) {
        for (int i = 1; i <= num; ++i) {
            if (!checkDirt(r - 1, dic[i])) 
                continue;
            for (int j = 1; j <= num; ++j) {
                if (!checkDirt(r - 2, dic[j])) 
                    continue;
                if (dic[i] & dic[j]) 
                    continue;
                for (int k = 1; k <= num; ++k) {
                    if (!checkDirt(r, dic[k])) 
                        continue;
                    if ((dic[k] & dic[i]) || (dic[k] & dic[j])) 
                        continue;
                    dp[r][k][i] = max(dp[r][k][i], dp[r - 1][i][j] + getSum(dic[k]));
                }
            }
        }
    }
    int ans = -0x3f3f3f3f;
    for (int i = 1; i <= num; ++i) 
        for (int j = 1; j <= num; ++j) 
            ans = max(ans, dp[n][i][j]);
    cout << ans << endl;
    return 0;
}