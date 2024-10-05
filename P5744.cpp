#include <iostream>
using namespace std;

struct node {
    string s;
    int age, score;
} nds[10];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> nds[i].s >> nds[i].age >> nds[i].score;
        ++nds[i].age;
        nds[i].score += nds[i].score / 5;
        if (nds[i].score > 600) nds[i].score = 600;
    }
    for (int i = 1; i <= n; ++i) cout << nds[i].s << ' ' << nds[i].age << ' ' << nds[i].score << '\n';
    return 0;
}