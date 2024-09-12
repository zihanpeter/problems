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
x&(x-1) 删除最右边的1
x&(-x) 获取最右边的1
x&1 判断奇偶
(x>>i)&1 判断第(i+1)位是否为1

