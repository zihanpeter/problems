#include <iostream>
using namespace std;
const int N = 1e3 + 5;
string s;
int a[N], k;
bool flag;

int main() {
    cin >> s >> k;
    for (int i = 0; i < s.length(); ++i) a[i + 1] = s[i] - '0';
    int st = 1;
    while (k) {
        int mini = st;
        for (int i = st; i <= st + k; ++i) 
            if (a[i] < a[mini]) mini = i;
        k -= mini - st;
        st = mini + 1;
        if (mini <= s.length() && (!a[mini] && flag || a[mini])) {
            cout << a[mini];
            flag = true;
        }
    }
    for (int i = st; i <= s.length(); ++i) 
        if (!a[i] && flag || a[i]) 
            cout << a[i];
    if (!flag) cout << 0;
    return 0;
}