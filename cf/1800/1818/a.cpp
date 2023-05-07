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
const int N = 3 + 123;

char s[N][N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        set<int> st;
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            st.insert(i);
        }
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!st.count(j)) {
                    continue;
                }
                if (s[j][i] != s[0][i]) {
                    st.erase(j);
                }
            }
        }
        cout << st.size() << endl;
    }
    return 0;
}