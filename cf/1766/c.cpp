#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e6;

int n;
string s, t;
vector<PII> ve;

void solve() {
    auto get = [](int p) {
        if (p == -1) {
            return 0;
        } else {
            return 1;
        }
    };
    for (int i = 1; i < ve.size(); ++i) {
        if (get(ve[i].first) != get(ve[i].second) &&
            get(ve[i - 1].first) != get(ve[i - 1].second)) {
            if (get(ve[i].first) != get(ve[i - 1].first)) {
                cout << "NO" << endl;
                return;
            }
            if (get(ve[i].second) != get(ve[i - 1].second)) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    db("?");
    for (int i = 0; i < ve.size(); ++i) {
        if (get(ve[i].first) != get(ve[i].second)) {
            continue;
        }
        int j = i;
        while (j + 1 < ve.size() &&
               get(ve[j + 1].first) == get(ve[j + 1].second)) {
            ++j;
        }
        int L = i - 1, R = j + 1;
        if (L < 0 || R >= ve.size()) {
            i = j;
            continue;
        }
        if (j - i + 1 & 1) {
            // even length
            if (get(ve[L].first) != get(ve[R].first)) {
                i = j;
                continue;
            }
            cout << "NO" << endl;
            db("???");
            return;
        } else {
            if (get(ve[L].first) == get(ve[R].first)) {
                i = j;
                continue;
            }
            cout << "NO" << endl;
            db("???");
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s >> t;
        ve.clear();
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'B' || t[i] == 'B') {
                ve.push_back({i, i});
                if (s[i] != 'B') {
                    ve.back().first = -1;
                }
                if (t[i] != 'B') {
                    ve.back().second = -1;
                }
            }
        }
        solve();
    }
    return 0;
}