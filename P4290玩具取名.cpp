#include <bits/stdc++.h>
using namespace std;
int W, I, N, G;
int Wi[], Ii[], Ni[], Gi[];
string s;
void dfs(string s, int l, int r) {
    string change;
    
}
int main() {
    cin >> W >> I >> N >> G;
    for (int i = 1; i <= W; ++i) 
        cin >> Wi[i];
    for (int i = 1; i <= I; ++i) 
        cin >> Ii[i];
    for (int i = 1; i <= N; ++i)
        cin >> Ni[i];
    for (int i = 1; i <= G; ++i)
        cin >> Gi[i];
    cin >> s;
    dfs("W", 1, s.length());
    dfs("I", 1, s.length());
    dfs("N", 1, s.length());
    dfs("G", 1, s.length());
    return 0;
}