#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const double eps = 1e-8;
const int N = 1e5 + 3;

int n;
double a[N], b[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    LL cnt = 1e18;
    cnt %= n;
    LL sum = accumulate(a, a + n, 0LL);
    for (int i = 0; i < n; ++i) {
        if (cnt == i) {
            cout << fixed << setprecision(10) << sum / (n + 1) * 2 << ' ';
        } else {
            cout << fixed << setprecision(10) << sum / (n + 1) << ' ';
        }
    }
    return 0;
}