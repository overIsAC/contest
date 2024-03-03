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

int n;

set<PII> get(int x, int y) {
    set<PII> st;
    for (int i = 0; i < 4; ++i) {
        tie(x, y) = PII(y, n - x - 1);
        st.insert({x, y});
    }
    return st;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        map<set<PII>, map<int, int>> mp;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                char c;
                cin >> c;

                mp[get(i, j)][c]++;
            }
        }
        int ans = 0;
        for (auto [u, v] : mp) {
            ans += min(v['0'], v['1']);
        }
        cout << ans << endl;
    }
    return 0;
}