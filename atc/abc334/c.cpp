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
const int N = 3 + 4e5;

int n, k;
int a[N];
LL pre[N], suf[N];

LL calc(vector<int>& b) {
    LL ans = 0;
    for (int i = 0; i + 1 < b.size(); i += 2) {
        ans += abs(b[i] - b[i + 1]);
    }
    return ans;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= k; ++i) {
        cin >> a[i];
    }

    set<int> st;
    for (int i = 1; i <= k; ++i) {
        st.insert(a[i]);
    }
    vector<int> b;
    for (int i = 1; i <= n; ++i) {
        b.push_back(i);
        if (!st.count(i)) {
            b.push_back(i);
        }
    }
    LL ans = calc(b);
    if (b.size() % 2 && b.size() > 1) {
        int m = b.size();
        b.insert(b.begin(), 0);
        for (int i = 2; i <= m; i += 2) {
            pre[i] = pre[i - 2] + abs(b[i] - b[i - 1]);
        }
        for (int i = m - 1; i >= 1; i -= 2) {
            suf[i] = suf[i + 2] + abs(b[i] - b[i + 1]);
        }
        for (int i = 1; i <= m; i += 2) {
            ans = min(ans, pre[i - 1] + suf[i + 1]);
        }
    }
    cout << ans << endl;

    return 0;
}