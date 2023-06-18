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
const int N = 3 + 4e4;

int n;
PII a[N];
int b[N], t;
int dp[N];
vector<int> ve[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        t = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i].first >> a[i].second;
            b[++t] = a[i].first;
            b[++t] = a[i].second;
        }
        sort(b + 1, b + t + 1);
        t = unique(b + 1, b + t + 1) - b - 1;
        for (int i = 1; i <= n; ++i) {
            a[i].first = lower_bound(b + 1, b + t + 1, a[i].first) - b;
            a[i].second = lower_bound(b + 1, b + t + 1, a[i].second) - b;
        }
        for (int i = 0; i <= t; ++i) {
            dp[i] = -1e8;
            ve[i].clear();
        }
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            ve[a[i].first].push_back(a[i].second);
        }
        for (int i = 1; i <= t; ++i) {
            multiset<int> st;
            dp[i] = max(dp[i - 1], dp[i]);
            for (int j = i; j <= t; ++j) {
                while (st.size() && *st.begin() < j) {
                    st.erase(st.begin());
                }
                for (auto &k : ve[j]) {
                    st.insert(k);
                }
                while (st.size() > 2) {
                    st.erase(--st.end());
                }
                if (st.size() == 2) {
                    dp[*st.rbegin()] = max(dp[*st.rbegin()], dp[i - 1] + 2);
                }
            }
        }
        cout << n - dp[t] << endl;
    }
    return 0;
}