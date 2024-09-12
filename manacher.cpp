#include <iostream>
#include <string>
using namespace std;
const int N = 1e6 + 5;
int p[N];
string src, s = "+#";
void manacher() {
    for (int i = 0; i < src.length(); ++i) {
        s += src[i];
        s += '#';
    }
    s += '-';
    int r = 0, c = 0;
    for (int i = 0; i < s.length(); ++i) {
        int j = 2 * c - i;
        if (j < c + r) 
            p[i] = min(p[j], c + r - i);
        while(s[i - p[i] - 1] == s[i + p[i] + 1]) 
            ++p[i];
        if (i + p[i] > c + r) {
            c = i;
            r = p[i];
        }
    }
    return;
}
int main() {
    cin >> src;
    manacher();
    int ans = 0;
    for (int i = 0; i < s.length(); ++i) 
        if (p[i] > p[ans]) 
            ans = i;
    cout << src.substr((ans - p[ans]) / 2, p[ans]);
    return 0;
}