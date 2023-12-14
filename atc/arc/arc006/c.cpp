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

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    set<int> st;
    st.insert(a[1]);
    for (int i = 2; i <= n; ++i) {
        auto p = st.lower_bound(a[i]);
        if (st.end() != p) {
            st.erase(p);
        }
        st.insert(a[i]);
    }
    cout << st.size() << endl;
    return 0;
}