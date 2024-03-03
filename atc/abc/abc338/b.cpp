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
    map<char, int> mp;
    string s;
    cin >> s;
    int mx = 0;
    for (auto& i : s) {
        ++mp[i];
        mx = max(mx, mp[i]);
    }
    for (auto& [u, v] : mp) {
        if (v == mx) {
            cout << u;
            break;
        }
    }
    return 0;
}