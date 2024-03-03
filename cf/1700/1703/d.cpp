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
        vector<string> a(n);
        for (auto& i : a) {
            cin >> i;
        }
        set<string> st(a.begin(), a.end());
        for (auto& i : a) {
            int have = 0;
            for (int j = 1; j < i.size(); ++j) {
                if (st.count(i.substr(0, j)) && st.count(i.substr(j))) {
                    have = 1;
                }
            }
            cout << have;
        }
        cout << endl;
    }
    return 0;
}