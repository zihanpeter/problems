#include <iostream>
#include <cmath>
using namespace std;
char s[5005][5005];
void f(int x, int y, int n){
    if(n == 1){
        s[x][y] = '/';
        s[x][y+1] = '\\';
        s[x+1][y-1] = '/';
        s[x+1][y] = '_';
        s[x+1][y+1] = '_';
        s[x+1][y+2] = '\\';
        return;
    }
    int k = 1<<n;
    int g = 1<<(n-1);
    f(x, y, n-1);  
    f(x+g, y-k/2, n-1);
    f(x+g, y+k/2, n-1); 
}
int main(){
    int n;
    cin>>n;
    for(int i = 1;i <= 2 * pow(2, n);i++){
        for(int j = 1;j <= 2 * pow(2, n);j++){
            s[i][j] = ' ';
        }
    }
    f(1, pow(2, n), n);  
    for(int i = 1;i <= 2 * pow(2, n);i++){
        for(int j = 1;j <= 2 * pow(2, n);j++){
            cout<<s[i][j];
        }
        cout<<endl;
    }
    return 0;
}