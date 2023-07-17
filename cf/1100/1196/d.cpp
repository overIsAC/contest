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
    const string t = "RGB";
    while (T--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        int ans = n;
        for (int j = 0; j < 3; ++j) {
            int temp = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] != t[(i + j) % 3]) {
                    ++temp;
                }
                if (i >= k - 1) {
                    ans = min(ans, temp);
                    if (s[(i - (k - 1))] != t[(i - (k - 1) + j) % 3]) {
                        --temp;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}