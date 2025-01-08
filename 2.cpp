#include <iostream>

using namespace std;
int a[100];
int main() {
    int ans = 0;

    for (int i = 1; i <= 50; ++i) {
        ans = ans ^ a[i];
    }

    return 0;
}