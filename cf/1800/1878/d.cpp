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
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    vector<PII> a(k);
    for (auto& [l, r] : a) {
        cin >> l;
    }
    for (auto& [l, r] : a) {
        cin >> r;
    }
    vector<map<int, int>> mp(k);

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        auto p = upper_bound(a.begin(), a.end(), make_pair(x, 1000000000));
        --p;
        int l = x, r = p->first + p->second - x;
        if (l > r) {
            swap(l, r);
        }
        int idx = p - a.begin();
        ++mp[idx][l];
        --mp[idx][r + 1];
    }
    for (int i = 0; i < k; ++i) {
        int l = a[i].first, r = a[i].second;
        while (l < r) {
            mp[i][l] += mp[i][l - 1];
            if (mp[i][l] % 2) {
                swap(s[l - 1], s[r - 1]);
            }
            ++l;
            --r;
        }
    }
    cout << s << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}