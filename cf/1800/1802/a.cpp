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
        sort(a + 1, a + n + 1, greater<int>());
        set<int> st;
        for (int i = 1; i <= n; ++i) {
            if (a[i] > 0) {
                st.insert(a[i]);
            } else {
                st.erase(-a[i]);
            }
            cout << st.size() << ' ';
        }
        cout << endl;
        map<int, int> mp;
        for (int i = 1; i <= n; ++i) {
            ++mp[abs(a[i])];
        }
        int cnt = 0;
        for (auto &i : mp) {
            if (i.second == 2) {
                ++cnt;
            }
        }
        for (int i = 1; i <= cnt; ++i) {
            cout << 1 << ' ' << 0 << ' ';
        }
        for (int i = 1; i <= n - 2 * cnt; ++i) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}