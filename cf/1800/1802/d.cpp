#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 5e5;

int n;
pair<LL, LL> a[N];
LL sufMax[N], sufMin[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i].first >> a[i].second;
        }
        sort(a + 1, a + n + 1, [&](const pair<LL, LL>& a, const pair<LL, LL>& b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        });
        set<LL> st;
        sufMax[n + 1] = -1e18;
        sufMin[n + 1] = 1e18;
        for (int i = n; i >= 1; --i) {
            sufMax[i] = max(sufMax[i + 1], a[i].second);
            sufMin[i] = min(sufMin[i + 1], a[i].second);
        }
        LL ans = 1e18;
        for (int i = 1; i < n; ++i) {
            if (a[i].first <= sufMax[i + 1]) {
                ans = min(ans, sufMax[i + 1] - a[i].first);
            } else {
                auto p = st.lower_bound(a[i].first);
                if (p != st.end()) {
                    ans = min(ans, *p - a[i].first);
                }
                if (p != st.begin()) {
                    --p;
                    ans = min(ans, abs(max(*p, sufMax[i + 1]) - a[i].first));
                }
            }
            st.insert(a[i].second);
        }
        auto p = st.lower_bound(a[n].first);
        if (p != st.end()) {
            ans = min(ans, abs(*p - a[n].first));
        }
        if (p != st.begin()) {
            --p;
            ans = min(ans, abs(*p - a[n].first));
        }
        cout << ans << endl;
    }
    return 0;
}