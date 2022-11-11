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
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 20000;

int n, x, y, a[N];

int main() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    set<int> st[2];
    st[0].insert(a[1]);
    int p = 0;
    db("");
    for (int i = 3; i <= n; i += 2)  {
        p ^= 1;
        st[p].clear();
        for (auto& j : st[p ^ 1]) {
            st[p].insert(j + a[i]);
            st[p].insert(j - a[i]);
        }
    }
    db("");
    if (!st[p].count(x)) {
        cout << "No" << endl;
        return 0;
    }
    st[0].clear();
    st[0].insert(0);
    p = 0;
    db("");
    for (int i = 2; i <= n; i += 2) {
        p ^= 1;
        st[p].clear();
        for (auto& j : st[p ^ 1]) {
            st[p].insert(j + a[i]);
            st[p].insert(j - a[i]);
        }
    }
    db("");
    if (!st[p].count(y)) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}