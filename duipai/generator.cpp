#include <iostream>
using namespace std;
int main() {
    freopen("sample.in", "w", stdout);
    srand(time(NULL));
    cout << 1 << ' ' << 5 << endl;
    for (int i = 1; i <= 5; ++i) {
        cout << rand() % 10 + 1 << ' ';
    }
    return 0;
}