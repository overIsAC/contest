#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        auto mex = [&]() {
            set<int> st;
            for (int i = 1; i <= n; ++i) {
                st.insert(a[i]);
            }
            int ans = 0;
            while (st.count(ans)) {
                ++ans;
            }
            return ans;
        };
        int v = mex();
        int L = 1e9, R = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] == v + 1) {
                R = i;
            }
        }
        for (int i = n; i >= 1; --i) {
            if (a[i] == v + 1) {
                L = i;
            }
        }
        if (!R) {
            int ok = 0;
            map<int, int> mp;
            for (int i = 1; i <= n; ++i) {
                if (++mp[a[i]] > 1) {
                    ok = 1;
                    break;
                }
                if (a[i] > v) {
                    ok = 1;
                    break;
                }
            }
            if (ok) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
            continue;
        }
        for (int i = L; i <= R; ++i) {
            a[i] = v;
        }
        if (mex() != v + 1) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}