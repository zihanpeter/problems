#include <iostream>
using namespace std;
int main() {
    do {
        system("./generator");
        system("./std");
        system("./test");
    } while (!system("diff -wB std.out test.out"));
    return 0;
}