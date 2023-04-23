#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 3 + 1e5;

LL a[N];
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    LL x = 0, y = 0;
    for (int i = 2; i <= n; ++i) {
        if (a[i] > a[i - 1]) {
            x += a[i] - a[i - 1];
        } else {
            y += a[i - 1] - a[i];
        }
    }
    cout << max(x, y) << endl;
    cout << abs(x - y) + 1 << endl;

    return 0;
}