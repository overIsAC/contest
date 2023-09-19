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
    cin >> n >> k;
    vector<PII> a(n);
    for (auto &[i, j] : a) {
        cin >> i;
        i %= k;
        if (i == 0) {
            i = k;
        }
    }
    for (int i = 0; i < n; ++i) {
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end(), [&](PII &a, PII &b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    });
    for (auto [x, y] : a) {
        cout << y << ' ';
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