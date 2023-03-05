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
const int N = 3 + 2e5;

int n, a[N], m;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        LL pre = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        int ans = 0;
        for (int i = m + 1; i <= n; ++i) {
            pre += a[i];
            if (a[i] < 0) q.push(a[i]);
            while (pre < 0) {
                pre -= q.top() * 2;
                q.pop();
                ++ans;
            }
        }
        db(ans);
        if (m > 1) {
            priority_queue<int> q2;
            if (a[m] > 0) {
                ++ans;
                a[m] = -a[m];
            }
            pre = a[m];
            for (int i = m - 1; i > 1; --i) {
                pre += a[i];
                if (a[i] > 0) q2.push(a[i]);
                while (pre > 0) {
                    pre -= q2.top() * 2;
                    q2.pop();
                    ++ans;
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}