#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e6 + 5;
char s[N];
int n, dp[N], maxLen, pos;

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; ++i) {
        if (s[i] == ')' && i - 1 - dp[i - 1] >= 1 && s[i - 1 - dp[i - 1]] == '(' || s[i] == ']' && i - 1 - dp[i - 1] >= 1 && s[i - 1 - dp[i - 1]] == '[') {
            dp[i] = dp[i - 1] + 2 + dp[i - 2 - dp[i - 1]];
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                pos = i - dp[i] + 1;
            }
        }
        
    }
    for (int i = pos; i < pos + maxLen; ++i) {
        printf("%c", s[i]);
    }
    return 0;
}