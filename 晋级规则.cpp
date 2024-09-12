#include <bits/stdc++.h>
using namespace std;
int k, n, m, q;
vector<string> list1, list2;
map<string, bool> dic1, dic2;
// bool operator > (const string &x, const string &y) {
//     return x > y;
// }
priority_queue<string, vector<string>, greater<string> > pq;
int main() {
    cin >> k >> n;
    for (int i = 1; i <= n; ++i) {
        string t;
        cin >> t;
        list1.push_back(t);
    }
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        string t;
        cin >> t;
        list2.push_back(t);
    }
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        string t;
        cin >> t;
        dic1[t] = true;
    }
    int cnt = 0;
    for (int i = 0; i < list1.size(); ++i) {
        if (dic1[list1[i]]) {
            pq.push(list1[i]);
            dic2[list1[i]] = true;
            ++cnt;
        }
        if (cnt == k) 
            break;
    }
    cnt = 0;
    for (int i = list2.size() - 1; i >= 0; --i) {
        if (!dic2[list2[i]] && dic1[list2[i]]) {
            ++cnt;
            pq.push(list2[i]);
        }
        if (cnt == k) 
            break;
    }
    cout << pq.size() << endl;
    while (!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }
    return 0;
}