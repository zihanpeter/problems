#include <iostream>
using namespace std;
int main() {
    system("./generator");
    system("./std");
    system("./test");
    while (!system("diff -wB std.out test.out")) {
        system("./generator");
        system("./std");
        system("./test");
    }
    return 0;
}