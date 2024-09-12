/*
#include <iostream>
using namespace std;
int n, m, v[505], w[505], s[505], f[6006];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i]>>s[i];//�۸�(weight)����ֵ(value)������
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            for(int k=1;k<=s[i];k++){
                if(j >= k*v[i]){
                    f[j] = max(f[j], f[j-k*v[i]]+k*w[i]);
                }else{
                    break;
                }
            }
        }
    }
    cout<<f[m];
    return 0;
}
*/





//��һ��д��
/*
for(int i=1;i<=n;i++){
    for(int k=1;k<=s[i];k++){
        for(int j=m;j>=0;j--){
            if(j >= v[i]){
                f[j] = max(f[j], f[j-v[i]]+w[i]);
            }
        }
    }
}
*/
#include <iostream>
using namespace std;
int n, m, v[5005], w[5005], f[6006];//ÿ����Ʒ��ఴ�ն����Ʒ��飬�ֳ�10�飬 ����v, w, s����ʮ��
int main(){
    int x, y, z, cnt=1;//cnt��ʾ�������Ʒ������
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x>>y>>z;//�۸񣬼�ֵ������
        //�����Ʒ���
        int k=1;
        while(z >= k){//���־ͼ���
            v[cnt] = k*x;//�÷ֵļ۸�
            w[cnt] = k*y;//�ķֵļ�ֵ
            ++cnt;
            z -= k;
            k *= 2;
        }
        if(z != 0){//�����Ʒ�����ʣ����������
            v[cnt] = z*x;//�÷ֵļ۸�
            w[cnt] = z*y;//�ķֵļ�ֵ
            ++cnt;
        }
    }
    for(int i=1;i<cnt;i++){
        for(int j=m;j>=0;j--){
            if(j >= v[i]){
                f[j] = max(f[j], f[j-v[i]]+w[i]);
            }
        }
    }
    cout<<f[m];
    return 0;
}
