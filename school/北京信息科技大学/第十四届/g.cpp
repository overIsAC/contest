#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 3 + 1e6;

int n, a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    LL ans = 0, sum = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, sum + a[i]);
        sum = max(0LL, sum + a[i]);
    }
    cout << ans << endl;

    return 0;
}