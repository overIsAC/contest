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

int digitSum(int x) {
    int ans = 0;
    while (x) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (auto &i : a) {
            cin >> i;
        }
        set<int> st;
        for (int i = 0; i < n; ++i) {
            st.insert(i);
        }
        while (q--) {
            int op, l, r, x;
            cin >> op;
            if (op == 1) {
                cin >> l >> r;
                l -= 1;
                r -= 1;
                for (auto it = st.lower_bound(l); it != st.end() && *it <= r;) {
                    int x = digitSum(a[*it]);
                    if (a[*it] == x) {
                        it = st.erase(it);
                    } else {
                        a[*it] = x;
                        ++it;
                    }
                }
            } else {
                cin >> x;
                cout << a[x - 1] << endl;
            }
        }
    }
    return 0;
}