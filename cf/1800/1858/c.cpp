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

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        set<int> st;
        vector<int> ans;
        for (int i = 2; i <= n / 2; ++i) {
            if (st.count(i)) {
                continue;
            }
            for (int j = i; j <= n; j *= 2) {
                ans.push_back(j);
                st.insert(j);
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (st.count(i)) {
                continue;
            }
            ans.push_back(i);
        }
        for (auto &i : ans) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}