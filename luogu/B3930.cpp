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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    int ans = 0;
    for (int i = 31; i >= 0; --i) {
        int cnt = 0;
        for (auto& j : a) {
            if (j >> i & 1) {
                ++cnt;
            }
        }
        if (cnt >= 2) {
            for (auto& j : a) {
                if (j >> i & 1) {
                } else {
                    j = 0;
                }
            }
            ans |= 1 << i;
        }
    }
    cout << ans << endl;
    return 0;
}