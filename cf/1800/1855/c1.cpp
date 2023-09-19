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
const int N = 3 + 1e5;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    if (is_sorted(a.begin(), a.end())) {
        cout << 0 << endl;
        return;
    }

    vector<PII> ans;
    auto op = [&](int i, int j) {
        ans.push_back({i + 1, j + 1});
        a[i] += a[j];
    };

    int flag = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i]) {
            for (int j = 0; j < 5; ++j) {
                op(i, i);
            }
            if (a[i] < 0) {
                op(0, i);
                flag = 1;
            } else {
                op(n - 1, i);
                flag = 0;
            }
            db(a[i]);
            break;
        }
    }
    if (flag) {
        for (int i = n - 2; i >= 0; --i) {
            while (a[i] + a[0] > a[i + 1]) {
                op(0, 0);
            }
            op(i, 0);
        }
    } else {
        for (int i = 1; i < n; ++i) {
            while (a[i - 1] > a[i] + a[n - 1]) {
                op(n - 1, n - 1);
            }
            op(i, n - 1);
        }
    }
    // for (auto &i : a) {
    //     cout << i << ' ';
    // }
    // cout << endl;
    cout << ans.size() << endl;
    for (auto [i, j] : ans) {
        cout << i << ' ' << j << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}