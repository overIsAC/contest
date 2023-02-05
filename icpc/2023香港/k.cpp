#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
using LL = long long;

const int N = 3 + 1e5;

int n, a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = __gcd(a[i], ans);
    }
    bool ok = true;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == a[1]) {
            continue;
        }
        if ((a[i] - 1) / 2 < a[1] && a[i] % a[1]) {
            ok = false;
            break;
        }
    }
    if (ok) {
        ans = max(ans, a[1]);
    }
    if (a[1] / 2 >= 1) {
        ans = max(a[1] / 2, ans);
    }

    cout << ans << endl;

    return 0;
}

/*

3
6 9 14

4
4 7 8 9
*/