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
    for (int i = 1; i <= 1111; ++i) {
        if (i % 3 == 0) {
            s += 'F';
        }
        if (i % 5 == 0) {
            s += 'B';
        }
    }
    // cout << s << endl;
    int T;
    cin >> T;
    while (T--) {
        string t;
        int k;
        cin >> k >> t;
        if (s.find(t) != string::npos) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}