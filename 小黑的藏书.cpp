#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, int> dic;
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        ++dic[s];
    }
    cout << dic.size() << endl;
    for (map<string, int>::iterator it = dic.begin(); it != dic.end(); it++) {
        cout << (*it).first << ' ' << (*it).second << endl;
    }
    return 0;
}