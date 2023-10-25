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

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    n = unique(a + 1, a + n + 1) - a - 1;
    set<int> st;
    for (int i = 0; i <= 10; ++i) {
        for (int j = 0; j <= 10; ++j) {
            if (n - i >= 1 && n - j >= 1) {
                st.insert(a[n - i] % a[n - j]);
            }
        }
    }
    if (st.size() == 1) {
        cout << -1 << endl;
    } else {
        auto p = st.end();
        --p;
        --p;
        cout << *p << endl;
    }

    return 0;
}