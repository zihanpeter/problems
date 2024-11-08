#include <iostream>
#include <algorithm>
using namespace std;
int n;
struct node {
    int num;
    string s;
} nds[25];

bool cmper(string x, string y) {
    if (x.length() < y.length()) return false;
    if (x.length() > y.length()) return true;
    return x > y;
}

bool cmp(node x, node y) {
    return cmper(x.s, y.s);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> nds[i].s;
        nds[i].num = i;
    }
    sort(nds + 1, nds + n + 1, cmp);
    cout << nds[1].num << endl << nds[1].s;
    return 0;
}