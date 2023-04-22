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
const int N = 3 + 2e5;

int n, a[N], b[N];
LL d[N];
multiset<LL> st[N], cur;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i <= n; ++i) {
        cin >> b[i];
    }
    st[n].insert(0);
    cur.insert(0);
    memset(d, 0x3f, sizeof(d));
    d[n] = 0;
    for (int i = n; i >= 1; --i) {
        if (cur.empty()) {
            break;
        }
        d[i] = *cur.begin();
        int x = max(0, i - a[i]);
        st[x].insert(d[i] + b[i]);
        cur.insert(d[i] + b[i]);
        for (auto &j : st[i]) {
            cur.erase(cur.find(j));
        }
    }
    if (cur.empty()) {
        cout << "shippai shi mashita" << endl;
    } else {
        cout << *cur.begin() << endl;
    }

    return 0;
}