#include <bits/stdc++.h>
using namespace std;
using LL = long long;
double a[11111], b[11111];

int main() {
    LL n;
    a[1] = 100;
    b[2] = 100;
    for (int i = 3; i <= 123; ++i) {
        a[i] = (a[i - 1] + a[i - 2]) / 2;
        b[i] = (b[i - 1] + b[i - 2]) / 2;
    }
    cin >> n;
    n = min(123LL, n);
    cout << fixed << setprecision(11) << a[n] << ' ' << b[n] << endl;

    return 0;
}