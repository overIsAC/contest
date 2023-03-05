#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int w, h;
int n;
int a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> w >> h;
        LL ans = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        ans = (LL)h * (a[n] - a[1]);
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        ans = max(ans, (LL)h * (a[n] - a[1]));
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        ans = max(ans, (LL)w * (a[n] - a[1]));
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        ans = max(ans, (LL)w * (a[n] - a[1]));
        cout << ans << endl;
    }
    return 0;
}