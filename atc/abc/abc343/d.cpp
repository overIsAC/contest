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
const int N = 3 + 2e5;

int n, t;
map<LL, int> mp;
int cnt;
LL z[N];

int main() {
    cin >> n >> t;
    mp[0] = n;
    cnt = 1;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (!--mp[z[a]]) {
            --cnt;
        }
        z[a] += b;
        if (!mp[z[a]]++) {
            ++cnt;
        }
        cout << cnt << endl;
    }

    return 0;
}