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

int n, a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (i == n || a[i + 1] == 1) {
            ans.push_back(a[i]);
        }
    }
    cout << ans.size() << endl;
    for (auto& i : ans) {
        cout << i << ' ';
    }
    return 0;
}