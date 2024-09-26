#include <iostream>
#include <cmath>
using namespace std;
double x[10], y[10];
int main() {
    for (int i = 1; i <= 3; ++i) scanf("%lf%lf", x + i, y + i);
    double zz = sqrt(pow(x[1] - x[2], 2) + pow(y[1] - y[2], 2));
    double zz2 = sqrt(pow(x[3] - x[2], 2) + pow(y[3] - y[2], 2));
    double zz3 = sqrt(pow(x[3] - x[1], 2) + pow(y[3] - y[1], 2));
    printf("%.2f", zz + zz2 + zz3);
    return 0;
}