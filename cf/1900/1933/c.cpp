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

void solve() {
    int a, b, l;
    cin >> a >> b >> l;
    set<int> st;
    for (int i = 1; i <= l; i *= a) {
        for (int j = i; j <= l; j *= b) {
            if (l % j == 0) {
                st.insert(l / j);
            }
        }
    }
    cout << st.size() << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}