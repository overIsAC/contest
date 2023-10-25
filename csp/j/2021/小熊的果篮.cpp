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

int n, a[N];
set<int> st[2];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        st[a[i]].insert(i);
    }
    while (st[0].size() || st[1].size()) {
        int p = n;
        for (int i = 0; i <= 1; ++i) {
            if (st[i].size()) {
                p = min(p, *st[i].begin());
            }
        }
        int c = 0;
        if (st[1].size() && p == *st[1].begin()) {
            c = 1;
        }
        while (true) {
            st[c].erase(p);
            cout << p << ' ';
            c = !c;
            if (st[c].size() && st[c].lower_bound(p) != st[c].end()) {
                p = *st[c].lower_bound(p);
            } else {
                break;
            }
        }
        cout << endl;
    }

    return 0;
}