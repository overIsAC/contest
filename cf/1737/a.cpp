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
    int T;
    cin >> T;
    while (T--) {
        string s;
        int n, k;
        cin >> n >> k;
        cin >> s;
        int ct[255] = {};
        for (int i = 0; i < n; ++i) {
            ++ct[s[i]];
        }
        for (int i = 0; i < k; ++i) {
            char a = 'a';
            int cnt = 0;
            while (cnt < n / k && ct[a]) {
                --ct[a];
                ++cnt;
                ++a;
            }
            cout << a;
        }
        cout << endl;
    }

    return 0;
}