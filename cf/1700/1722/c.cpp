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
        vector<string> a(n), b(n), c(n);
        map<string, int> mp;
        for (auto& i : a) {
            cin >> i;
            ++mp[i];
        }
        for (auto& i : b) {
            cin >> i;
            ++mp[i];
        }
        for (auto& i : c) {
            cin >> i;
            ++mp[i];
        }
        int u = 0, v = 0, w = 0;
        for (auto& i : a) {
            if (mp[i] == 1) {
                u += 3;
            }
            if (mp[i] == 2) {
                u += 1;
            }
        }
        for (auto& i : b) {
            if (mp[i] == 1) {
                v += 3;
            }
            if (mp[i] == 2) {
                v += 1;
            }
        }
        for (auto& i : c) {
            if (mp[i] == 1) {
                w += 3;
            }
            if (mp[i] == 2) {
                w += 1;
            }
        }
        cout << u << ' ' << v << ' ' << w << endl;
    }
    return 0;
}