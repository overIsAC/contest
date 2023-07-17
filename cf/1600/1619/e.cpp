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

int n, a[N];

void solve() {
    map<int, int> mp;
    priority_queue<int> q;
    for (int i = 1; i <= n; ++i) {
        ++mp[a[i]];
    }
    cout << mp[0] << ' ';
    auto f = [&](int x) {
        while (x--) {
            cout << -1 << ' ';
        }
        cout << endl;
    };
    if (!mp[0]) {
        f(n);
        return;
    }
    LL c = 0;
    while (mp[0] > 1) {
        q.push(0);
        --mp[0];
    }
    for (int i = 1; i <= n; ++i) {
        cout << mp[i] + c << ' ';
        if (mp[i]) {
            while (mp[i] > 1) {
                q.push(i);
                --mp[i];
            }
        } else {
            if (q.size()) {
                c += i - q.top();
                q.pop();
            } else {
                f(n - i);
                return;
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        solve();
    }
    return 0;
}