#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    int prefix = 0, suffix = 0;
    if (s == t.substr(0, n)) {
        prefix = 1;
    }
    if (s == t.substr(m - n)) {
        suffix = 1;
    }
    if (prefix && suffix) {
        cout << 0 << endl;
    } else if (prefix) {
        cout << 1 << endl;
    } else if (suffix) {
        cout << 2 << endl;
    } else {
        cout << 3 << endl;
    }

    return 0;
}