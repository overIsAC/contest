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

set<LL> st;
int n, k;

int main() {
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    st.insert(1);
    int ans = 0;
    for (int i = 1; i <= k + 1; ++i) {
        LL x = *st.begin();
        st.erase(x);
        ans = x;
        for (auto &i : a) {
            st.insert(i * x);
        }
        while (st.size() > k) {
            st.erase(--st.end());
        }
    }
    cout << ans << endl;
    return 0;
}