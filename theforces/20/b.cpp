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
        vector<PII> a(n);
        for (auto &i : a) {
            cin >> i.first;
        }
        for (auto &i : a) {
            cin >> i.second;
        }
        map<int, int> mp1, mp2;
        for (auto &i : a) {
            ++mp1[i.first];
            ++mp2[i.second];
        }
        int ok = 1;
        for (auto [x, y] : mp1) {
            if (y + mp2[x] > n) {
                ok = 0;
            }
        }
        if (ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}