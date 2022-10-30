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
const int N = 3 + 1e5;

int n, a[N];
int ans[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            ans[i] = 0;
        }
        set<int> s;
        for (int i = 1; i < n; ++i) {
            ans[a[i]] = i + 1;
            s.insert(a[i]);
        }
        int p = 1;
        while (s.count(p)) {
            ++p;
        }
        ans[p] = 1;
        for (int i = 1; i <= n; ++i) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}