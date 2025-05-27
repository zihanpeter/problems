#include <iostream>
using namespace std;

bool check(int x) {
    for (int i = 2; i * i <= x; ++i) 
        if (!(x % i)) return false;
    return true;
}

int main() {
    int x;
    cin >> x;
    if (check(x)) cout << "SHOUT!" << endl;
    else cout << "SIT DOWN!" << endl;
    return 0;
}