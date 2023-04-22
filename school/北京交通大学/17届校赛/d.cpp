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
    int n;
    string a, b;
    cin >> n >> a >> b;
    vector<int> ve;
    string ans(n, -1);
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) {
            ans[i] = a[i] ^ 1;
        } else {
            ve.push_back(i);
        }
    }
    for (int i = 0; i < ve.size(); ++i) {
        if (i & 1) {
            ans[ve[i]] = a[ve[i]] ^ 1;
        } else {
            ans[ve[i]] = a[ve[i]];
        }
    }
    cout << ans;
    return 0;
}