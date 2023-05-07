#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 3 + 1e5;

int n, a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += abs(a[i] - a[(n + 1) / 2]);
    }
    cout << ans << endl;

    return 0;
}