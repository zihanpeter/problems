#include <iostream>
using namespace std;

bool check(int x) {
    for (int i = 2; i * i <= x; ++i) 
        if (!(x % i)) return false;
    return true;
}

int main() {
    int L, cnt = 0, sum = 0;
    cin >> L;

    for (int i = 2; sum <= L; ++i) {
        if (check(i)) {
            if (i + sum > L) break;
            cout << i << endl;
            sum += i;
            ++cnt;
        }
    }
    cout << cnt << endl;
    return 0;
}