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

int check(int i, int j) {
    set<char> st;
    string a = to_string(i), b = to_string(j);
    st.insert(a.begin(), a.end());
    st.insert(b.begin(), b.end());
    if (st.size() == 1) {
        return 1;
    }
    return 0;
}

int main() {
    int n, a;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        for (int j= 1; j <= a; ++j) {
            if (check(i, j)) {
                ans += 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}