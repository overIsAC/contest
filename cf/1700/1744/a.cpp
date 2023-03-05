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
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a[233], n;
        string s;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cin >> s;
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] != s[j] && a[i] == a[j]) {
                    ok = false;
                }
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}