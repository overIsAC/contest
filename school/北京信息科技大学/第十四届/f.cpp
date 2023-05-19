#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 3 + 2e5;

int n, a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    LL ans = 0;
    for (int i = 2; i <= n; ++i) {
        if (a[i - 1] < a[i]) {
            ans += a[i] - a[i - 1];
        }
    }
    cout << ans << endl;
    return 0;
}