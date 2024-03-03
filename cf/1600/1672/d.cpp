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
    vector<int> a(n), b(n);
    for (auto& i : a) {
        cin >> i;
    }
    for (auto& i : b) {
        cin >> i;
    }
    if (a.back() != b.back()) {
        cout << "NO" << endl;
        return;
    }
    map<int, int> mp;
    for (auto& i : a) {
        ++mp[i];
    }
    int last = 0;
    while (b.size()) {
        if (!mp[a.back()]) {
            a.pop_back();
            continue;
        }
        if (a.back() == b.back()) {
            last = a.back();
            a.pop_back();
            b.pop_back();

            --mp[last];

            continue;
        }
        if (last == b.back() && mp[last]) {
            a.push_back(last);
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}