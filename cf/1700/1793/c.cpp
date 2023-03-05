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

int n, a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        set<int> st;
        for (int i = 1; i <= n; ++i) {
            st.insert(i);
        }
        int l = 1, r = n;
        while (l <= r) {
            if (a[l] == *st.begin()) {
                ++l;
                st.erase(st.begin());
                continue;
            }
            if (a[l] == *prev(st.end())) {
                ++l;
                st.erase(prev(st.end()));
                continue;
            }
            if (a[r] == *st.begin()) {
                --r;
                st.erase(st.begin());
                continue;
            }
            if (a[r] == *prev(st.end())) {
                --r;
                st.erase(prev(st.end()));
                continue;
            }
            break;
        }
        if (l <= r) {
            cout << l << ' ' << r << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}