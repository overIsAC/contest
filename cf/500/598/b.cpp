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

string s;
int m, l[N], r[N], k[N];

int main() {
    
    cin >> s;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> l[i] >> r[i] >> k[i];
        --l[i];
        --r[i];
        k[i] %= r[i] - l[i] + 1;
    }
    for (int i = 0; i < s.size(); ++i) {
        int p = i;
        for (int j = m - 1; j >= 0; --j) {
            if (l[j] <= p && p <= r[j]) {
                p = (p - l[j] - k[j] + r[j] - l[j] + 1) % (r[j] - l[j] + 1) + l[j];
            }
        }
        cout << s[p];
    }
    return 0;
}