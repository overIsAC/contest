#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 5e5;

int n, m;
PII a[N];
bool win[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
            win[i] = false;
        }
        sort(a + 1, a + n + 1);
        int ans = 0;
        int mx = 0;
        for (int i = 1; i <= n; ++i) {
            if (m >= a[i].first) {
                m -= a[i].first;
                ++ans;
                win[a[i].second] = true;
                mx = a[i].first;
            } else {
                break;
            }
        }
        if (ans == n) {
            cout << 1 << endl;
            continue;
        }
        sort(a + 1, a + n + 1, [&](const PII& a, const PII& b) {
            return a.second < b.second;
        });
        db(ans);
        if (ans + 1 <= n && m + mx >= a[ans + 1].first) {
            db(__LINE__);
            cout << n - ans << endl;
            continue;
        }
        if (m + mx >= a[ans].first) {
            db(__LINE__);
            cout << n - ans + 1 << endl;
            continue;
        }
        if (win[ans]) {
            db(__LINE__);
            cout << n - ans + 1 << endl;
            continue;
        }

        cout << n - ans + 1 << endl;
    }
    return 0;
}