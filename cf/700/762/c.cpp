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

char s[N], t[N];
int n, m;
int cnt[N];

int main() {
    cin >> s + 1;
    cin >> t + 1;
    n = strlen(s + 1);
    m = strlen(t + 1);
    set<int> st;
    st.insert(0);
    for (int i = 1, j = 1; i <= n; ++i) {
        if (s[i] == t[j]) {
            st.insert(j);
            cnt[i] = j;
            ++j;
            if (j == m + 1) {
                cout << t + 1 << endl;
                return 0;
            }
        }
    }
    int l = *st.rbegin() + 1, r = m;
    for (int i = n, j = m; i >= 1; --i) {
        if (cnt[i]) {
            st.erase(cnt[i]);
        }
        if (s[i] == t[j]) {
            if (j - *st.rbegin() - 1 < r - l + 1) {
                l = *st.rbegin() + 1;
                r = j - 1;
            }
            --j;
        }
    }

    if (l == 1 && r == m) {
        cout << "-" << endl;
        return 0;
    }
    for (int i = 1; i <= m; ++i) {
        if (l <= i && i <= r) {
            continue;
        }
        cout << t[i];
    }

    return 0;
}