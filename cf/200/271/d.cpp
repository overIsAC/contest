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
const int N = 3 + 1500 * 1500;

int tr[N][26], ed[N], id;

int main() {
    string a, b;
    int k;
    cin >> a >> b >> k;
    int ans = 0;
    for (int i = 0; i < a.size(); ++i) {
        int cnt = 0, rt = 0;
        for (int j = i; j < a.size(); ++j) {
            if (b[a[j] - 'a'] == '0') {
                ++cnt;
            }
            if (cnt > k) {
                break;
            }
            int &p = tr[rt][a[j] - 'a'];
            if (!p) {
                p = ++id;
            }
            rt = p;
            if (!ed[rt]++) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}