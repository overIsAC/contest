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
const int N = 3 + 2e5;

int n, a[N], b[N];

int f(int x) {
    int num = 0;
    do {
        x /= 10;
        ++num;
    } while (x);
    return num;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
        }
        map<int, int> mp;
        int cnt[10] = {0};
        for (int i = 1; i <= n; ++i) {
            if (a[i] < 10)
                ++cnt[a[i]];
            else
                ++mp[a[i]];
            if (b[i] < 10)
                --cnt[b[i]];
            else
                --mp[b[i]];
        }
        int ans = 0;
        for (auto &i : mp) {
            ans += abs(i.second);
            cnt[f(i.first)] += i.second;
        }

        for (int i = 2; i <= 9; ++i) {
            ans += abs(cnt[i]);
        }

        cout << ans << endl;
    }
    return 0;
}