#include <iostream>
#include <random>
using namespace std;
int main() {
    freopen("sample.in", "w", stdout);
    mt19937 rnd(time(NULL));

    cout << 1 << ' ' << 5 << endl;
    for (int i = 1; i <= 5; ++i) {
        cout << rnd() % 10 + 1 << ' ';
    }
    return 0;
}