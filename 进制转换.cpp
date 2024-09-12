#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int main(){
    string s;
    int n, m;
    cin>>n>>s>>m;
    int t, d = 0, k;
    for (int i = 0;i < s.size();i++){
        if (s[i] >= 'A' && s[i] <= 'Z'){
            t = s[i] - 'A' + 10;
        }else{
            t = s[i] - '0';
        }
        k = pow(n, s.size()-1-i);
        d += t * k;
    }
    int b;
    char c;
    string ans;
    while (d > 0){
        b = d % m;
        if (b >= 10){
            c = b + 'A' - 10;
        }else{
            c = b + '0';
        }
        d /= m;
        ans += c;
    }
    for (int i = ans.size()-1;i >= 0;i--){
        cout<<ans[i];
    }
    return 0;
}