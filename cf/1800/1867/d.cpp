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

int n, k;
int a[N];
vector<int> edge[N];
int du[N];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    map<int, int> mp;
    auto ins = [&](int x) {
        ++mp[x];
    };
    auto del = [&](int x) {
        if (!--mp[x]) {
            mp.erase(x);
        }
    };
    for (int i = 1; i < k; ++i) {
        ins(a[i]);
    }
    for (int i = 1, j = 1; i <= n; ++i) {
        ins(a[i]);
        if (i - j + 1 > k) {
            del(a[j]);
        }
        while (i - j + 1 > mp.size() || ) {
            del(a[j]);
            ++j;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}