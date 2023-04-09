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
    reverse(s.begin(), s.end());
    for (int i = 0; i < 100; ++i) {
        string t = s;
        reverse(t.begin(), t.end());
        if (s == t) {
            cout << "YES" << endl;
            return 0;
        }
        s += '0';
    }
    cout << "NO" << endl;
    return 0;
}