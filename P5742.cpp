#include <iostream>
using namespace std;
const int N = 1e3 + 5;

int n;
struct node {
    int a, b, c;
    bool ass() {
        return a + b > 140 && a * 7 + b * 3 >= 800;
    }
} nds[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> nds[i].c >> nds[i].a >> nds[i].b;
        if (nds[i].ass()) cout << "Excellent\n";
        else cout << "Not excellent\n";
    }
    return 0;
}