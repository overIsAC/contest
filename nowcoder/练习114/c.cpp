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

mt19937 rnd(time(NULL));

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int id = 0;
    for (auto &i : a) {
        cin >> i;
    }
    vector<PII> interval;
    for (int i = 0; i < n; ++i) {
        if (a[i] > m) {
            continue;
        }
        int j = i;
        while (j + 1 < n && a[j + 1] == a[j] + 1 && a[j + 1] <= m) {
            ++j;
        }
        interval.push_back({i, j});
        i = j;
    }
    sort(interval.begin(), interval.end(), [&](PII &u, PII &v) {
        if (a[u.first] == a[v.first]) {
            return a[u.second] > a[v.second];
        }
        return a[u.first] < a[v.first];
    });
    vector<int> cnt(m + 1);
    int ans = 0;
    for (auto &i : interval) {
        int flag = 0;
        for (int j = a[i.first]; j <= a[i.second]; ++j) {
            if (!cnt[j]) {
                flag = 1;
            }
        }
        ans += flag;
        for (int j = a[i.first]; j <= a[i.second]; ++j) {
            cnt[j] = 1;
        }
    }
    if (accumulate(cnt.begin(), cnt.end(), 0) != m) {
        ans = -1;
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}