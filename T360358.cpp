#include <iostream>
using namespace std;
int main() {
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        bool flag = false;
        for (int i = 0; i <= 11; ++i) 
            if (n - i * 111 >= 0 && !((n - i * 111) % 11)) {
                printf("Yes\n");
                flag = true;
                break;
            }
        if (!flag) printf("No\n");
    }
    return 0;   
}