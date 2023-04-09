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
const int N = 3 + 3e5;

PII a[N];
int n;
map<PII, int> mp;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) {
                continue;
            }
            if (a[i].first > a[j].first || a[i].first == a[j].first && a[i].second > a[j].second) {
                mp[{a[i].first - a[j].first, a[i].second - a[j].second}] += 1;
            }
        }
    }
    LL ans = 0;
    for (auto &i : mp) {
        ans += i.second * (i.second - 1) / 2;
    }
    cout << ans / 2 << endl;

    return 0;
}