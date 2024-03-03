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
    string s;
    cin >> s;
    map<char, int> mp;
    for (auto& i : s) {
        ++mp[i];
    }
    for (int i = 1; i <= s.size(); ++i) {
        if (mp[s[i - 1]] == 1) {
            cout << i << endl;
        }
    }
    return 0;
}