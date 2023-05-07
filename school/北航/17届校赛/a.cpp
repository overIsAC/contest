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
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    cin >> m;
    vector<int> b(m);
    for (auto &i : b) {
        cin >> i;
    }
    int cnt = 0;
    for (auto &i : b) {
        cnt += i & 1;
    }
    LL ans = 0;
    sort(a.rbegin(), a.rend());
    for (auto &i : a) {
        if (i % 2) {
            continue;
        }
        if (cnt) {
            --cnt;
            continue;
        }
        ans += i;
    }
    cout << ans << endl;
    return 0;
}