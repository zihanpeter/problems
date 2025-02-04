#include <iostream>
#include <queue>
#include <list>
using namespace std;
const int N = 1e5 + 5;
int n, m;
int t[N];

bool tong[N]; // ��¼��̭����Ϣ
queue<int> q; // ��¼��̭��˳��
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) 
        cin >> t[i];
    int cnt = 0; // cnt��¼��̭�˶��ٸ���
    int tr = 0; // tr��¼ʱ��
    while (cnt != n - 1) {
        for (int i = 1; i <= n; ++i) {
            if (tong[i]) 
                continue;
            tr += t[i];
            if (tr > m) { // i����̭��
                tong[i] = true;
                q.push(i);
                ++cnt;
                tr = 0;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!tong[i]) {
            cout << i << endl;
            break;
        }
    }
    while (!q.empty()) {
        cout << q.front() << ' ';
        q.pop();
    }
    return 0;
}