#include <iostream>
using namespace std;

int a = 0x01020304, b, c, d, e;

int main(){
	
	// & | ^ ~
	printf("%x\n", a); 
	b |= (a >> 24);
	c |= (a >> 16)&0xff;
	d |= (a >> 8)&0xff;
	e |= a&0xff;
	e <<= 8;
	e |= d;
	e <<= 8;
	e |= c;
	e <<= 8;
	e |= b;
	printf("%x", e);
	return 0;
}
x&(x-1) ɾ�����ұߵ�1
x&(-x) ��ȡ���ұߵ�1
x&1 �ж���ż
(x>>i)&1 �жϵ�(i+1)λ�Ƿ�Ϊ1

