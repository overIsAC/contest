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

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<PII> a(n);
        for (auto &i : a) {
            cin >> i.first;
        }
        for (auto &i : a) {
            cin >> i.second;
        }
        LL ans = a[0].first * a[0].second;
        LL sum = 0, cnt = 0;
        for (auto &i : a) {
            ans = max(ans, (LL)i.first * i.second);
            if (i.second > 0) {
                ++cnt;
                sum += i.first;
            }
        }
        if (cnt) {
            ans = max(ans, sum * cnt);
        }
        sort(a.begin(), a.end(), greater<PII>());
        for (auto &i : a) {
            if (i.second < 0) {
                sum += i.first;
                cnt += i.second;
            }
            ans = max(ans, sum * cnt);
        }
        cout << ans << endl;
    }
    return 0;
}