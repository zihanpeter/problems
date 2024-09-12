#include <bits/stdc++.h>
using namespace std;
int n, A, B, maxf[55][55], minf[55][55], c1, c2, c3;
char s[55][55];
int main() {
    scanf("%d%d%d", &n, &A, &B);
    for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
        if (i == j || s[i][j] == '=') {
            maxf[i][j] = minf[i][j] = 0;
            continue;
        }
        if (s[i][j] == '+') maxf[i][j] = 2, minf[i][j] = 1;
        else if (s[i][j] == '-') maxf[i][j] = -1, minf[i][j] = -2;
        else if (s[i][j] == '?') maxf[i][j] = 2, minf[i][j] = -2;
    }
    for (int k = 1; k <= n; ++k) for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
        maxf[i][j] = min(maxf[i][j], maxf[i][k] + maxf[k][j]);
        minf[i][j] = max(minf[i][j], minf[i][k] + minf[k][j]);
    }
    for (int i = 1; i <= n; ++i) for (int j = i + 1; j <= n; ++j) {
        if (i == A || i == B || j == A || j == B) continue;
        if (minf[A][i] > maxf[j][B] || minf[A][j] > maxf[i][B]) ++c1;
        if (minf[A][i] == maxf[A][i] && maxf[A][i] == minf[j][B] && minf[j][B] == maxf[j][B] || minf[B][i] == maxf[B][i] && maxf[B][i] == minf[j][A] && minf[j][A] == maxf[j][A]) ++c2;
        if (minf[j][B] > maxf[A][i] || minf[i][B] > maxf[A][j]) ++c3;
    }
    printf("%d %d %d", c1, c2, c3);
    return 0;
}