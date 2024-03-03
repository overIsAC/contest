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
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; ++i) {
        mp[a[i - 1]].push_back(i);
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;

        cin >> l >> r;
        auto& ve = mp[a[l]];
        auto calc = [&](int l, int r) {
            return upper_bound(ve.begin(), ve.end(), r) - lower_bound(ve.begin(), ve.end(), l);
        };

        if (calc(l, r) == r - l + 1) {
            cout << "-1 -1" << endl;
            continue;
        }

        int L = l + 1, R = r;
        while (L < R) {
            int mid = (L + R) / 2;
            if (calc(l, mid) == mid - l + 1) {
                L = mid + 1;
            } else {
                R = mid;
            }
        }
        cout << l << ' ' << L << endl;
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}