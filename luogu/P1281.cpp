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

int m, n, a[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int l = *max_element(a + 1, a + n + 1), r = 1e9;
    vector<PII> ans;

    auto ok = [&](int z) {
        ans.clear();
        int cnt = 0, first = n;
        for (int i = n; i >= 1; --i) {
            cnt += a[i];
            if (cnt > z) {
                ans.push_back({i + 1, first});
                cnt = a[i];
                first = i;
            }
        }
        ans.push_back({1, first});
        return ans.size() <= m;
    };

    while (l < r) {
        int mid = l + r >> 1;
        if (ok(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    ok(r);
    reverse(ans.begin(), ans.end());

    for (auto& i : ans) {
        cout << i.first << ' ' << i.second << endl;
    }

    return 0;
}