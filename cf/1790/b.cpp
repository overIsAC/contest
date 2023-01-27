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
        int r, s;
        cin >> n >> s >> r;
        int t = s - r;
        vector<int> ans;
        ans.push_back(t);
        s -= t;
        for (int i = 1; i < n; ++i) {
            ans.push_back(1);
            s -= 1;
        }
        int p = 1;
        while (s > 0) {
            ans[p] += 1;
            s -= 1;
            ++p;
            if (p == ans.size()) {
                p = 1;
            }
        }
        for (auto& i : ans) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}